#include "Pic.h"

using namespace std;


Picture frame(const Picture& pic)
{
	return new Frame_Pic(pic.p);
}

Picture hcat(const Picture& l, const Picture& r)
{
	return new HCat_Pic(l.p, r.p);
}

Picture vcat(const Picture& t, const Picture& b)
{
	return new VCat_Pic(t.p, b.p);
}

// 用一个vector<string>类型对象构造一个Picture类型对象
Picture::Picture(const vector<string>& v) : p(new String_Pic(v)) { }


ostream& operator<<(ostream& os, const Picture& picture)
{
	const Pic_base::ht_sz ht = picture.p->height();
	for (Pic_base::ht_sz i = 0; i != ht; ++i)
	{
		picture.p->display(os, i, false);
		os << endl;
	}
	return os;
}

Pic_base::wd_sz String_Pic::width() const
{
	Pic_base::wd_sz n = 0;
	for (Pic_base::ht_sz i = 0; i != data.size(); ++i)
	{
		n = max(n, data[i].size());
	}
	return n;
}

void String_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
	wd_sz start = 0;

	// 如果row没有超出范围，就输出第row行
	if (row < height())
	{
		os << data[row];
		start = data[row].size();
	}

	// 如有必要，补齐输出各行
	if (do_pad)
		pad(os, start, width());
}


void VCat_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
	wd_sz w = 0;
	if (row < top->height())
	{
		top->display(os, row, do_pad);
		w = top->width();
	}
	else if (row < height())
	{
		bottom->display(os, row - top->height(), do_pad);
		w = bottom->width();
	}

	if (do_pad)
		pad(os, w, width());
}

void HCat_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
	left->display(os, row, do_pad || row < right->height());
	right->display(os, row, do_pad);
}


void Frame_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
	if (row >= height())
	{
		// 超出范围
		if (do_pad)
			pad(os, 0, width());
	}
	else
	{
		if (row == 0 || row == height() - 1)
		{
			// 在最顶行或最底行
			os << string(width(), '*');
		}
		else if (row == 1 || row == height() - 2)
		{
			// 在第二行或倒数第二行
			os << "*";
			pad(os, 1, width() - 1);
			os << "*";
		}
		else
		{
			// 在内部图形中
			os << "* ";
			p->display(os, row - 2, true);
			os << " *";
		}
	}
}


void Pic_base::pad(std::ostream& os, wd_sz beg, wd_sz end)
{
	while (beg != end)
	{
		os << " ";
		++beg;
	}
}
