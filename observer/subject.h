#include "observer.h"

class MySubject : public ISubject
{
public:
	enum Message { ADD, REMOVE, UPDATE};
};
