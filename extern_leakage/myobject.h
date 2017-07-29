/// \author Martin Reddy
/// \brief  Showing how "internal" details can be leaked. 外部连接泄漏，破坏封装性

#ifndef MYOBJECT_H
#define MYOBJECT_H

namespace apibook {

///
/// A dummy object.
/// The meat of this example is in myobject.cpp
///
class MyObject
{
public:
  void SetValue(int value);
  int GetValue() const;

private:
	int mValue;
};

}

#endif
