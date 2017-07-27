// Martin Reddy

#include "modulea.h"
#include "moduleb.h"

int main(int, char **)
{
	apibook::ModuleB b;
	int              closure = 42;

	// add a callback for ModuleA to ModuleB
	b.SetCallback(apibook::ModuleA::StaticMethod, &closure);
	// tell ModuleB to invoke all its callbacks
	b.DoAction();

	return 0;
}
