/// \author Martin Reddy
/// \brief  A graph that contains multiple nodes.

#include "graph.h"

namespace apibook {

void Graph::AddNode(const Node &node)
{
	mNodes.push_back(node);
}

void Graph::Refresh()
{
	std::vector<Node>::iterator it;
	for ( it = mNodes.begin(); it != mNodes.end(); ++it)
	{
		Node &node = *it;
		node.SetVisited();
	}
}

}
