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

//Breadth-First Search algorithm implementation
class BFS : public Algorithm
{
private:
	//Current list of Nodes waiting to be processed
	list<Node*> queue;

public:
	BFS(string nStart, string nEnd = "") {}
	using Algorithm::Algorithm;

	//Runs Breadth-First search algorithm and returns the path taken
	string Run(void)
	{
		//Mark starting place as visited
		visited[distance(map.begin(), find(map.begin(), map.end(), current))] = true;
		queue.push_back(current);

		while (true)
		{
			count++;

			current = queue.front();
			path += (current->GetName() + "\n");
			queue.pop_front();

			//If end Node has been reached, escape algorithm 
			if (current == endRef) return path;

			//Reference to Nodes adjacent to the to-be-processed Node
			Node** adjacents = current->GetAdjacents();

			//Push all unvisited adjacent Nodes into the queue
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

//Depth-First Search algorithm implementation
class DFS : public Algorithm
{
private:
	//For flagging when path as complete
	bool complete = false;

	//DFS recursive method
	void Recur(Node* nP)
	{
		//If completion flagged, prevent further recursion to bring algorithm to an end
		if (complete) return;

		//Mark the to-be-processed Node as visited
		visited[distance(map.begin(), find(map.begin(), map.end(), nP))] = true;
		path += (nP->GetName() + "\n");

		//If specified end is reached, flag completion
		if (nP == endRef) complete = true;

		//Reference to Nodes adjacent to the to-be-processed Node
		Node** adjacents = nP->GetAdjacents();

		//Recursive traverse to adjacent Nodes
		for (int i = 0; i < 4; i++)
		{
			if (adjacents[i])
			{
				//Index position the current adjacent Node is in within the map vector
				int pos = distance(map.begin(), find(map.begin(), map.end(), adjacents[i]));
				if (!visited[pos]) Recur(adjacents[i]);
			}
		}
	}
public:
	DFS(string nStart, string nEnd = "") {}
	using Algorithm::Algorithm;

	//Runs Depth-First search algorithm and returns the path taken
	string Run(void)
	{
		Recur(startRef);
		return path;
	}
};