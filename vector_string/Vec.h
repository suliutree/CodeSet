#ifndef VEC_H
#define VEC_H

#include <algorithm>
#include <cstddef>
#include <memory>

using std::max;

template <class T> class Vec {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;

	Vec() { create(); }
	explicit Vec(size_type n, const T& t = T()) { create(n, t); }

	Vec(const Vec& v) { create(v.begin(), v.end()); }
	Vec& operator=(const Vec&);
	~Vec() { uncreate(); }

	T& operator[](size_type i) { return data[i]; }
	const T& operator[](size_type i) const { return data[i]; }

	void push_back(const T& t)
	{
		if (avail == limit)
			grow();
		unchecked_append(t);
	}

	size_type size() const { return avail - data; }

	iterator begin() { return data; }
	const_iterator begin() const { return data; }
	iterator end() { return avail;}
	const_iterator end() const { return avail; }

	void clear() { uncreate(); }
	bool empty() const { return data == avail;}

private:
	iterator data;		// Vec�е���Ԫ�� 
	iterator avail;		// Vec��ĩԪ�صĺ���һ��Ԫ��
	iterator limit;		// �·����ڴ���ĩԪ�غ���һ��Ԫ��

	// ��<memory>ͷ�ļ����ṩ��һ����Ϊallocator<T>���࣬�����Է���һ��Ԥ�����ڴ洢T����
	// ��������δ��ʼ�����ڴ�飬������һ��ָ������ڴ���ͷԪ�ص�ָ��
	std::allocator<T> alloc;	// �����ڴ����Ķ���

	// Ϊ�ײ���������ռ䲢�������г�ʼ��
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	// ɾ�������е�Ԫ�ز��ͷ���ռ�õ��ڴ�
	void uncreate();

	// ֧��push_back�ĺ���
	void grow();
	void unchecked_append(const T&);
};


template <class T> void Vec<T>::create()
{
	data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val)
{
	data = alloc.allocate(n);
	limit = avail = data + n;
	std::uninitialized_fill(data, limit, val);
}

template <class T> void Vec<T>::create(const_iterator i, const_iterator j)
{
	data = alloc.allocate(j - i);
	limit = avail = std::uninitialized_copy(i, j, data);
}

template <class T> void Vec<T>::uncreate()
{
	if (data)
	{
		// �����෴��˳��ɾ�����캯�����ɵ�Ԫ��
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);

		// ����ռ�õ������ڴ�ռ�
		alloc.deallocate(data, limit - data);
	}

	// ����ָ���Ա���Vec���Ͷ���Ϊ��
	data = avail = limit = 0;
}

template <class T> void Vec<T>::grow()
{
	// ����չ�����Сʱ��Ϊ�������ʵ��ʹ�õ�������С���ڴ�ռ䣨���Vec����Ϊ�գ���ѡ��һ��Ԫ�ؽ����ڴ���䣩
	// max��������������������ͬһ���ͣ�limit-data��������ptrdiff_t
	size_type new_size = max(2 * (limit - data), ptrdiff_t(1));

	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	uncreate();

	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

// �ڽ����Ź����Ԫ�غ��λ��������һ��Ԫ��
// ����availָ��һƬ�·��䵫��δ����ʼ�����ڴ�ռ�
template <class T> void Vec<T>::unchecked_append(const T& val)
{
	alloc.construct(avail++, val);
}

template <class T> Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
	// �ж��Ƿ�������Ҹ�ֵ
	if (&rhs ��= this)
	{
		// ɾ���������������
		uncreate();

		// ���Ҳิ��Ԫ�ص����
		create(rhs.begin(), rhs.end());
	}

	return *this; 
}


#endif