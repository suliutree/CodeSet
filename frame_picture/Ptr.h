#ifndef GUARD_ptr_h
#define GUARD_ptr_h

#include <cstddef>
#include <stdexcept>

// Ptr类用于管理引用计数以实现对基础对象的共享
// 每个与Ptr类型对象关联的对象都有一个相应的引用计数，这个引用计数用于表示我们生成了该对象的多少个副本
template <class T> class Ptr {
public:
	// 用于在需要时有条件的复制对象
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
		默认构造函数与带一个T*参数的构造函数被用于生成一个新的Ptr类型的对象，因此它们要为一个新的
	引用计数（size_t类型）分配内存，然后将该计数器的值设为1。
		复制构造函数无须生成一个新的对象，它对参数所给出的Ptr<T>类型对象进行指针复制，然后使计数器
	加1，以表示指向这个T类型对象的指针比以前又多了一个。
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
	// 通过在对左操作数对象的引用计数减一之前首先对右操作数对象的引用计数加一来解决自我赋值的问题
	++*rhs.refptr;
	// 如果在为引用计数减一时使它达到零值，那么左操作数就是与底层对象关联的最后一个Ptr类型对象
	// 由于我们要抹去左操作数对象的值，因此要调用delete函数删除对象的最后一个引用
	if (--*refptr == 0)
	{
		delete refptr;
		delete p;
	}

	// 复制右操作数的值
	refptr = rhs.refptr;
	p = rhs.p;
	return *this;
}

template <class T> Ptr<T>::~Ptr()
{
	// 检查要删除的Ptr对象是否是指向T对象的最后一个引用
	// 如果是，则删除指针所指向的对象并释放其占用的内存
	if (--*refptr == 0)
	{
		delete refptr;
		delete p;
	}
}

#endif