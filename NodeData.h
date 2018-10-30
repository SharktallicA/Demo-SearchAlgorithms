#pragma once

class Node;

//For transporting data on an adjacent Node
class NodeData
{
public:
	//The Node being transported
	Node* node = nullptr;
	//Cost to travel to this Node
	int cost = 0;

	NodeData(void) {}
	NodeData(Node* nNode, int nCost)
	{
		node = nNode;
		cost = nCost;
	}
};
