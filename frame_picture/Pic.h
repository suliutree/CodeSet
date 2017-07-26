#ifndef GUARD_pic_h
#define GUARD_pic_h

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Ptr.h"

using std::max;

// 接口类，这里是前置声明，因为Pic_base类中对operator<<函数的友元声明中用到了const Picture&的类型
class Picture;

// 基类
class Pic_base {
	// 为啥友元声明？输出运算符会激活height()函数与display()函数，因此要求该运算符可以访问这些函数
	friend std::ostream& operator<<(std::ostream&, const Picture&);
	// 派生类为啥友元声明？
	// 派生类只能访问类的对象自身拥有的保护成员，但是它们没有访问其它对象的保护成员的特权 P298
	friend class Frame_Pic;
	friend class HCat_Pic;
	friend class VCat_Pic;
	friend class String_Pic;

	typedef std::vector<std::string>::size_type ht_sz;
	typedef std::string::size_type wd_sz;

	virtual wd_sz width() const = 0;
	virtual ht_sz height() const = 0;
	virtual void display(std::ostream&, ht_sz, bool) const = 0;

public:
	virtual ~Pic_base() { }

protected:
	// 由于希望可以从任何一个派生类中访问这个函数，因此将此函数定义为Pic_base类的一个成员函数
	// 并且将其定义为静态的（static）和保护类型的（protected）
	static void pad(std::ostream& os, wd_sz, wd_sz);
};

// 接口类
class Picture {
	// 由于这些操作都会用到Picture类型对象里的Ptr类型对象，因此必须获得访问Ptr类成员的权力
	friend std::ostream& operator<<(std::ostream&, const Picture&);
	friend Picture frame(const Picture&);
	friend Picture hcat(const Picture&, const Picture&);
	friend Picture vcat(const Picture&, const Picture&);

public:
	Picture(const std::vector<std::string>& = std::vector<std::string>());

private:
	Picture(Pic_base* ptr) : p(ptr) { } 
	// 将每个操作通过Ptr类型对象转给底层的派生类对象以实现该操作
	Ptr<Pic_base> p;
};

// 由于以下这些操作不会改变正在作用的Picture类型对象的状态，因此没有必要将它们定义为Picture的成员函数
Picture frame(const Picture&);
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);


class String_Pic : public Pic_base 
{
	// 将Picture类定义成String_Pic类的一个友元类，这样就可以通过Picture类访问String_Pic类的构造函数
	friend class Picture;
	std::vector<std::string> data;
	// 从向量类参数v中将底层的字符串复制到打他数据成员里。这是整个程序中唯一对字符进行复制的地方。
	// 在其它地方，我们只是复制Ptr<Pic_base>对象，它实际上只是复制了指针，使引用计数器增加一。
	String_Pic(const std::vector<std::string>& v) : data(v) { }

	ht_sz height() const { return data.size(); }
	wd_sz width() const;
	void display(std::ostream&, ht_sz, bool) const;
};


class VCat_Pic : public Pic_base
{
	friend Picture vcat(const Picture&, const Picture&);
	Ptr<Pic_base> top, bottom;
	VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b) :
		top(t), bottom(b) { }

	wd_sz width() const
	{
		return max(top->width(), bottom->width());
	}

	ht_sz height() const
	{
		return top->height() + bottom->height();
	}

	void display(std::ostream&, ht_sz, bool) const;
};


class HCat_Pic : public Pic_base
{
	friend Picture hcat(const Picture&, const Picture&);
	Ptr<Pic_base> left, right;
	HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r) :
		left(l), right(r) { }

	wd_sz width() const { return left->width() + right->width(); }
	ht_sz height() const { return max(left->height(), right->height()); }

	void display(std::ostream&, ht_sz, bool) const;
};


class Frame_Pic : public Pic_base
{
	// 这里定义为友元函数是因为frame函数中要生成Frame_Pic类型的对象，而Frame_Pic类的构造函数是私有的
	friend Picture frame(const Picture&);
	Ptr<Pic_base> p;
	// 只需要把将要被加上框架的源对象复制到Ptr类型对象中即可
	Frame_Pic(const Ptr<Pic_base> pic) : p(pic) { }

	wd_sz width() const { return p->width() + 4; }
	ht_sz height() const { return p->height() + 4; }
	void display(std::ostream&, ht_sz, bool) const;
};


#endif
