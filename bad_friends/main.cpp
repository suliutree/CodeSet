/// \author Martin Reddy
/// \brief  Showing how friends can be subverted in C++.

#include "node.h"

// 友元关系仅仅是建立在其他类的名字基础之上，因此客户可以创建它们自己的名为Graph的类，
// 这些类能够访问Node的所有受保护成员和私有成员。
// 避免使用友元更好的解决方案是由Graph对象维持它已经访问过的节点列表。
// create our own Graph class, which is a friend of Node
namespace apibook {

class Graph
{
public:
	void ViolateAccess(Node &node)
	{
		// call a private method in Node
		node.SetVisited();
	}
};

}

int main(int, char **)
{
	apibook::Node node;
	apibook::Graph local_graph;

	// Use our local Graph class to break into the Node object
	local_graph.ViolateAccess(node);

	return 0;
}
