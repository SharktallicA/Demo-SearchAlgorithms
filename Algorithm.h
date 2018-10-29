#pragma once
#include "Node.h"
#include <list>

class Algorithm
{
protected:
	string startName, endName;

	//Reference to all Nodes within the virtual "map"
	vector<Node*> map;

	//Reference to current processed Node
	Node* current = nullptr;

	//Reference to start Node
	Node* startRef = nullptr;

	//Reference to end Node
	Node* endRef = nullptr;

	//Amount of iterations the algorithm has used to complete the search 
	int count = 1;

	//Path the algorithm has used
	string path = "";

	//Flags which Nodes have been visited
	vector<bool> visited;

public:
	Algorithm(void) {}
	Algorithm(vector<Node*> nMap, string nStart, string nEnd = "")
	{
		map = nMap;
		startName = nStart;
		endName = nEnd;

		visited = vector<bool>(map.size());
		for (bool b : visited) b = false;

		//get specified start as Node object
		for (Node* n : map)
		{
			if (n->GetName() == startName)
			{
				startRef = current = n;
				break;
			}
		}

		//get specified end as Node object
		for (Node* n : map)
		{
			if (n->GetName() == endName)
			{
				endRef = n;
				break;
			}
		}
	}

	//Runs search algorithm and returns the path taken
	virtual string Run(void) { return ""; }
};