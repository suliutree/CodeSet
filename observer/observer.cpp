#include "observer.h"

using namespace std;

ISubject::ISubject() {}
ISubject::~ISubject() {}

void ISubject::Subscribe(int message, IObserver *observer)
{
	if (observer)
	{
		ObserverMap::iterator it = mObservers.find(message);
		if (it == mObservers.end())
		{
			mObservers[message] = ObserverList();	
		}
		mObservers[message].push_back(observer);
	}
}

void ISubject::UnSubscribe(int message, IObserver *observer)
{
	if (observer)
	{
		ObserverMap::iterator it = mObservers.find(message);
		if (it != mObservers.end())
		{
			ObserverList::iterator itOb = mObservers[message].begin();
			for ( ; itOb != mObservers[message].end(); itOb++)
			{
				if (observer == *itOb)
				{
					mObservers[message].erase(itOb);
					break;
				}
			}
		}
	}
}

void ISubject::Notify(int message)
{
	ObserverMap::iterator it = mObservers.find(message);
	if (it != mObservers.end())
	{
		ObserverList::iterator itOb = mObservers[message].begin();
		for ( ; itOb != mObservers[message].end(); itOb++)
		{
			(*itOb)->Update(message);
		}
	
	}
}
