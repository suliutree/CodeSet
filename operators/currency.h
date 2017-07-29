/// \author Martin Reddy
/// \brief  Demonstrating good C++ operator style.

#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>

namespace apibook {

///
/// A class to hold a single currency value
///
class Currency
{
public:
	explicit Currency(int value);
	~Currency();
	Currency(const Currency &obj);

	// these operators must be declared as member functions
	Currency &operator =(const Currency &rhs);
	Currency &operator +=(const Currency &rhs);
	Currency &operator -=(const Currency &rhs);
	Currency &operator *=(const Currency &rhs);
	Currency &operator /=(const Currency &rhs);

	int GetValue() const;

private:
	class Impl;
	Impl *mImpl;
};

// these operators can (and should) be declared as free functions
Currency operator +(const Currency &lhs, const Currency &rhs);
Currency operator -(const Currency &lhs, const Currency &rhs);
Currency operator *(const Currency &lhs, const Currency &rhs);
Currency operator /(const Currency &lhs, const Currency &rhs);

bool operator ==(const Currency &lhs, const Currency &rhs);
bool operator !=(const Currency &lhs, const Currency &rhs);
bool operator <(const Currency &lhs, const Currency &rhs);
bool operator >(const Currency &lhs, const Currency &rhs);
bool operator <=(const Currency &lhs, const Currency &rhs);
bool operator >=(const Currency &lhs, const Currency &rhs);

std::ostream& operator <<(std::ostream &os, const Currency &obj);

}

#endif
