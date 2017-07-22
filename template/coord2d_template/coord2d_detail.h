// Martin Reddy

#ifndef COORD2D_DETAIL_H
#define COORD2D_DETAIL_H

#include "coord2d.h"

// define the implementation for the Coord2D class template

namespace apibook {

template <class T>
Coord2D<T>::Coord2D(T x, T y) : mX(x), mY(y)
{
}

template <class T>
T Coord2D<T>::GetX() const
{
	return mX;
}

template <class T>
T Coord2D<T>::GetY() const
{
	return mY;
}

template <class T>
void Coord2D<T>::SetX(T x)
{
	mX = x;
}

template <class T>
void Coord2D<T>::Multiply(T dx, T dy)
{
	mX *= dx;
	mY *= dy;
}


}

#endif