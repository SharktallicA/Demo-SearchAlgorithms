#pragma once
#include "Utility.h"

using namespace std;

class Node
{
private:
	string name = "";

	//linked list hardpoints (adjacent) Nodes; [0] up, [1] right, [2] down, [3] left
	Node* adj[4] = { nullptr };

public:
	Node(string nName)
	{
		name = nName;
	}
	~Node(void) { for (Node* n : adj) delete n; }

	//Defines the layout of Nodes relative to this one
	void MapRelativies(Node* nUp = nullptr, Node* nDown = nullptr, Node* nLeft = nullptr, Node* nRight = nullptr)
	{
		if (adj[0] || adj[1] || adj[2] || adj[3])
		{
			cout << "ILLEGAL CALL: Node already mapped!" << endl;
			return;
		}

		adj[0] = nUp;
		adj[1] = nRight;
		adj[2] = nDown;
		adj[3] = nLeft;
	}

	//Returns this Nodes's name
	string GetName(void) { return name; }

	Node* GetUp(void) { return adj[0]; }
	Node* GetRight(void) { return adj[1]; }
	Node* GetDown(void) { return adj[2]; }
	Node* GetLeft(void) { return adj[3]; }
	Node** GetAdjacents(void) { return adj; }
};