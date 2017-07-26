#ifndef GUARD_ptr_h
#define GUARD_ptr_h

#include <cstddef>
#include <stdexcept>

// Ptr�����ڹ������ü�����ʵ�ֶԻ�������Ĺ���
// ÿ����Ptr���Ͷ�������Ķ�����һ����Ӧ�����ü�����������ü������ڱ�ʾ���������˸ö���Ķ��ٸ�����
template <class T> class Ptr {
public:
	// ��������Ҫʱ�������ĸ��ƶ���
	void make_unique()
	{
		if (*refptr != 1)
		{
			--*refptr;
			refptr = new size_t(1);
			p = p ? clone(p) : 0;
		}
	}

	/* 
		Ĭ�Ϲ��캯�����һ��T*�����Ĺ��캯������������һ���µ�Ptr���͵Ķ����������ҪΪһ���µ�
	���ü�����size_t���ͣ������ڴ棬Ȼ�󽫸ü�������ֵ��Ϊ1��
		���ƹ��캯����������һ���µĶ������Բ�����������Ptr<T>���Ͷ������ָ�븴�ƣ�Ȼ��ʹ������
	��1���Ա�ʾָ�����T���Ͷ����ָ�����ǰ�ֶ���һ����
	*/
	Ptr() : p(0), refptr(new size_t(1)) { }
	Ptr(T* t) : p(t), refptr(new size_t(1)) { }
	Ptr(const Ptr& h) : p(h.p), refptr(h.refptr) { ++*refptr; }

	Ptr& operator=(const Ptr&);
	~Ptr();
	operator bool() const { return p; }
	T& operator*() const;
	T* operator->() const;

private:
	T* p;
	std::size_t* refptr;

};


template <class T> T& Ptr<T>::operator*() const 
{ 
	if (p) 
		return *p;
	throw std::runtime_error("unbound Ptr");
}

template <class T> T* Ptr<T>::operator->() const 
{ 
	if (p) 
		return p;
	throw std::runtime_error("unbound Ptr");
}

template <class T> Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
{
	// ͨ���ڶ����������������ü�����һ֮ǰ���ȶ��Ҳ�������������ü�����һ��������Ҹ�ֵ������
	++*rhs.refptr;
	// �����Ϊ���ü�����һʱʹ���ﵽ��ֵ����ô�������������ײ������������һ��Ptr���Ͷ���
	// ��������ҪĨȥ������������ֵ�����Ҫ����delete����ɾ����������һ������
	if (--*refptr == 0)
	{
		delete refptr;
		delete p;
	}

	// �����Ҳ�������ֵ
	refptr = rhs.refptr;
	p = rhs.p;
	return *this;
}

template <class T> Ptr<T>::~Ptr()
{
	// ���Ҫɾ����Ptr�����Ƿ���ָ��T��������һ������
	// ����ǣ���ɾ��ָ����ָ��Ķ����ͷ���ռ�õ��ڴ�
	if (--*refptr == 0)
	{
		delete refptr;
		delete p;
	}
}

#endif