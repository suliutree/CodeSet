// Martin Reddy

#ifndef MODULEA_H
#define MODULEA_H

#include <string>

namespace apibook {

///
/// An object that wishes to receive a callback from another
/// module. A static function is used to avoid the complication
/// of calling a function on a specific instance of the object.
///
class ModuleA
{
public:
    /// The static function callback
	static void StaticMethod(const std::string &name, void *data);
};

}

#endif
