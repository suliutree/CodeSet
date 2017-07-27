// Martin Reddy

#include "modulea.h"
#include <iostream>

using std::cout;
using std::endl;

namespace apibook {

void ModuleA::StaticWrapper(void *obj, const std::string &name, void *data)
{
	ModuleA *self = static_cast<ModuleA *>(obj);
	self->InstanceMethod(name, data);
}

void ModuleA::InstanceMethod(const std::string &name, void *data)
{
	int closure = *static_cast<int *>(data);
	cout << "In instance callback: '" << name << "' (closure=" << closure << ")" << endl;
}

}
