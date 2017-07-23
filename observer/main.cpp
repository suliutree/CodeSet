#include <iostream>
#include <string>

#include "subject.h"

using std::cout;
using std::endl;
using std::string;

class MyObserver : public IObserver
{
public:
	explicit MyObserver(const string &str) :
		mName(str)
		{}

	void Update(int message)
	{
		cout << mName << " Receive message ";
		cout << message << endl;
	}

private:
	string mName;
};

int main(int, char**)
{
	MyObserver observer1("observer1");
	MyObserver observer2("observer2");
	MyObserver observer3("observer3");

	MySubject subject;
	subject.Subscribe(MySubject::ADD, &observer1);
	subject.Subscribe(MySubject::ADD, &observer2);
	subject.Subscribe(MySubject::REMOVE, &observer3);
	subject.Subscribe(MySubject::UPDATE, &observer2);
	subject.Subscribe(MySubject::UPDATE, &observer3);

	subject.Notify(MySubject::ADD);
	subject.Notify(MySubject::REMOVE);
	subject.Notify(MySubject::UPDATE);

	return 0;
}
