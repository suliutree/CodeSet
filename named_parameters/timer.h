// Martin Reddy

#ifndef TIMER
#define TIMER

namespace apibook {

///
/// A simple class that demonstrates the Named Parameter Idiom.
///
class Timer
{
public:
	Timer();
	~Timer();

	/// Allow this class to be copyable
	Timer(const Timer &);
	const Timer &operator =(const Timer &);

	/// An NPI-style setter for the timer delay
	Timer &SetDelay(float t);
	/// An NPI-style setter for whether the timer repeats
	Timer &SetSingleShot(bool ss);

	/// Start the timer with the current settings
	Timer &Start();

private:
	class Impl;
	Impl *mImpl;
};

}

#endif
