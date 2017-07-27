// Martin Reddy

#include "moduleb.h"

namespace apibook {

ModuleB::ModuleB() : mObject(NULL), mCallback(NULL), mClosure(NULL)
{
}

void ModuleB::SetCallback(void *obj, CallbackType cb, void *data)
{
	mObject = obj;
	mCallback = cb;
	mClosure = data;
}

void ModuleB::DoAction()
{
	if (mCallback)
	{
		(*mCallback)(mObject, "Hello World", mClosure);
	}
}

}
