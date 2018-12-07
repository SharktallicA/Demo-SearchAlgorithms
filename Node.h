#pragma once
#include "Utility.h"
#include "NodeData.h"

using namespace std;

//Locational representation
class Node
{
private:
	//Node's locate name
	string name = "";

	//Linked list hardpoints (adjacent) Nodes; [0] up, [1] right, [2] down, [3] left
	Node* adj[4] = { nullptr };

	//Linked list travel costs
	int adjCost[4] = { 0 };

public:
	Node(string nName) { name = nName; }
	~Node(void) { for (Node* n : adj) delete n; }

	//Defines the layout of Nodes relative to this one
	void MapRelativies(NodeData nUp, NodeData nDown, NodeData nLeft, NodeData nRight)
	{
		if (adj[0] || adj[1] || adj[2] || adj[3]) throw "ERROR: Node already mapped!\n";

		adj[0] = nUp.node;
		adj[1] = nRight.node;
		adj[2] = nDown.node;
		adj[3] = nLeft.node;

		adjCost[0] = nUp.cost;
		adjCost[1] = nRight.cost;
		adjCost[2] = nDown.cost;
		adjCost[3] = nLeft.cost;
	}

	string GetName(void) { return name; }

	Node* GetUp(void) { return adj[0]; }
	Node* GetRight(void) { return adj[1]; }
	Node* GetDown(void) { return adj[2]; }
	Node* GetLeft(void) { return adj[3]; }

	NodeData GetUpData(void) { return NodeData(adj[0], adjCost[0]); }
	NodeData GetRightData(void) { return NodeData(adj[1], adjCost[1]); }
	NodeData GetDownData(void) { return NodeData(adj[2], adjCost[2]); }
	NodeData GetLeftData(void) { return NodeData(adj[3], adjCost[3]); }

	vector<Node*> GetAdjacents(void) { return vector<Node*>(begin(adj), end(adj)); }

	vector<NodeData> GetAdjacentsData(void)
	{
		vector<NodeData> adjacents(4);
		adjacents[0] = NodeData(adj[0], adjCost[0]);
		adjacents[1] = NodeData(adj[1], adjCost[1]);
		adjacents[2] = NodeData(adj[2], adjCost[2]);
		adjacents[3] = NodeData(adj[3], adjCost[3]);
		return adjacents;
	}
	vector<NodeData> GetValidAdjacentsData(void)
	{
		vector<NodeData> valids;
		for (int i = 0; i < 4; i++) if (adj[i]) valids.push_back(NodeData(adj[i], adjCost[i]));
		return valids;
	}
};