/// \file   myclass.cpp
/// \author Martin Reddy
/// \brief  Classes with and without virtual function calls.

#include "myclass.h"

NonVirtualClass::NonVirtualClass() :
	mCounter(0)
{
}

NonVirtualClass::~NonVirtualClass()
{
}

void NonVirtualClass::DoSomething()
{
	mCounter++;
}

BaseClass::BaseClass() :
	mCounter(0)
{
}

BaseClass::~BaseClass()
{
}

void BaseClass::DoSomething()
{
}

void DerivedClass::DoSomething()
{
	mCounter++;
}
