/// \author Martin Reddy
/// \brief  A single node in a graph. Graph is a friend.

#ifndef NODE_H
#define NODE_H

namespace apibook {

///
/// A node in a graph.
///
class Node
{
public:
	friend class Graph;

private:
	void SetVisited();
	bool IsVisited() const;
};

}

#endif
