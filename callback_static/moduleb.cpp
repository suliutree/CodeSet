// Martin Reddy

#include "moduleb.h"

namespace apibook {

ModuleB::ModuleB() : mCallback(NULL), mClosure(NULL)
{
}

void ModuleB::SetCallback(CallbackType cb, void *data)
{
	mCallback = cb;
	mClosure = data;
}

void ModuleB::DoAction()
{
	if (mCallback)
	{
		(*mCallback)("Hello World", mClosure);
	}
}

}
