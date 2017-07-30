/// \author Martin Reddy
/// \brief  A graph that contains multiple nodes.

#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"
#include <vector>

namespace apibook {

///
/// A graph of nodes.
///
class Graph
{
public:
	/// Add a node to the graph
	void AddNode(const Node &node);

	/// Refresh the contents of the graph
	void Refresh();

private:
	std::vector<Node> mNodes;
};

}

#endif
