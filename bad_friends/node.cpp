/// \author Martin Reddy
/// \brief  A single node in a graph. Graph is a friend.

#include "node.h"
#include <iostream>

using std::cout;
using std::endl;

namespace apibook {

void Node::SetVisited()
{
	cout << "Private method called!" << endl;
}

bool Node::IsVisited() const
{
	cout << "Private method called!" << endl;
	return false;
}

}
