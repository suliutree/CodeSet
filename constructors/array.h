/// \author Martin Reddy
/// \brief  An example of using constructors and assignment.

#ifndef ARRAY_H
#define ARRAY_H

#include <string>

namespace apibook {

///
/// An array of elements.
///
class Array
{
public:
	/// default constructor
	Array();
	/// non-default constructor
	explicit Array(int size);
	/// destructor
	~Array();
	/// copy constructor
	Array(const Array &in_array);
	/// assignment operator
	Array &operator = (const Array &in_array);

	/// Return the element at the given array index
	std::string Get(int index) const;
	/// Set the element at the given array index
	bool Set(int index, const std::string &str);
	/// Return the number of elements in the array
	int Size() const;
	/// Output the array contents to stdout
	void Print() const;

private:
	int mSize;
	std::string *mArray;
};

}

#endif
