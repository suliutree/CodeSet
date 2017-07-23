#include <map>
#include <vector>

class IObserver
{
public:
	virtual ~IObserver() {}
	virtual void Update(int message) = 0;
};

class ISubject
{
public:
	ISubject();
	virtual ~ISubject();

	virtual void Subscribe(int message, IObserver *observer);
	virtual void UnSubscribe(int message, IObserver *observer);
	virtual void Notify(int message);

private:
	typedef std::vector<IObserver *> ObserverList;
	typedef std::map<int, ObserverList> ObserverMap;
	ObserverMap mObservers;
};
