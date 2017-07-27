// Martin Reddy

#include "modulea.h"
#include "moduleb.h"

int main(int, char **)
{
	apibook::ModuleB b;
	apibook::ModuleA a;
	int     closure = 42;

	// add a callback for ModuleA to ModuleB
	b.SetCallback(&a, apibook::ModuleA::StaticWrapper, &closure);
	// tell ModuleB to invoke all its callbacks
	b.DoAction();

	return 0;
}
