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

	//Reference to end Node
	Node* endRef = nullptr;

	//Amount of iterations the algorithm has used to complete the search 
	int count = 1;

	//Path the algorithm has used
	string path = "";

public:
	Algorithm(void) {}
	Algorithm(vector<Node*> nMap, string nStart, string nEnd = "")
	{
		map = nMap;
		startName = nStart;
		endName = nEnd;
	}

	//Runs search algorithm and returns the path taken
	virtual string Run(void) { return ""; }
};

class BFS : public Algorithm
{
private:
	//Flags which Nodes have been visited
	vector<bool> visited;

	//Current list of Nodes waiting to be processed
	list<Node*> queue;

	void Prep(void)
	{
		visited = vector<bool>(map.size());
		for (bool b : visited) b = false;

		//get specified start as Node object
		for (Node* n : map)
		{
			if (n->GetName() == startName)
			{
				current = n;
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

		//mark starting place as visited
		visited[distance(map.begin(), find(map.begin(), map.end(), current))] = true;
		queue.push_back(current);
	}
public:
	BFS(string nStart, string nEnd = "") {}
	using Algorithm::Algorithm;

	//Runs Breadth-First search algorithm and returns the path taken
	string Run(void)
	{
		Prep();

		while (true)
		{
			count++;

			current = queue.front();
			path += (current->GetName() + "\n");
			queue.pop_front();
			if (current == endRef) return path;

			Node** adjacents = current->GetAdjacents();

			for (int i = 0; i < 4; i++)
			{
				if (adjacents[i])
				{
					//Index position the current adjacent Node is in within the map vector
					int pos = distance(map.begin(), find(map.begin(), map.end(), adjacents[i]));
					if (!visited[pos])
					{
						visited[pos] = true;
						queue.push_back(adjacents[i]);
					}
				}
			}
		}
		return path;
	}
};