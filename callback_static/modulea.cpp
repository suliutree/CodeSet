// Martin Reddy

#include "modulea.h"
#include <iostream>

using std::cout;
using std::endl;

namespace apibook {

void ModuleA::StaticMethod(const std::string &name, void *data)
{
	int closure = *static_cast<int *>(data);
	cout << "In static callback: '" << name << "', closure=" << closure << endl;
}

}
