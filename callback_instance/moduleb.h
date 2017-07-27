// Martin Reddy

#ifndef MODULEB_H
#define MODULEB_H

#include <string>
#include <stdlib.h>

namespace apibook {

///
/// An object that can register a callback function and then
/// invoke that callback when desired.
///
class ModuleB
{
public:
	/// A type for the function signature that is accepted as a callback
	typedef void (*CallbackType)(void *obj, const std::string &name, void *data);

	ModuleB();

	/// Set the callback function. Only one callback can be registered.
	void SetCallback(void *obj, CallbackType cb, void *data);
	/// Call the callback function.
	void DoAction();

private:
	void         *mObject;
	CallbackType mCallback;
	void         *mClosure;
};

}

#endif
