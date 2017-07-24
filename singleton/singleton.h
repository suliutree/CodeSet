// Martin Reddy

#ifndef SINGLETON_H
#define SINGLETON_H

#include <string>

///
/// A class that enforces the policy that only one
/// instance is ever created.
///
class Singleton
{
public:
	/// Return the single instance of this class
	static Singleton &GetInstance();

	/// Return some class-specific single-instance state
	int GetState();

private:
	// Prevent construction and copying of this class
	Singleton();
	~Singleton();
	Singleton(const Singleton &);
	const Singleton &operator =(const Singleton &);
};

#endif
