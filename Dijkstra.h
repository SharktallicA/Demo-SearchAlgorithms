#pragma once
#include "SearchAlgorithm.h"

//Dijkstra's shortest path finding algorithm implementation
class Dijkstra : public SearchAlgorithm
{
protected:
	//Stores temporal distance values for each Node
	vector<int> distances;

	//Flags which Nodes have been visited
	vector<Node*> previous;

	//Processes the distances between neighbouring Nodes to the current Node
	void calculateTentatives(void)
	{
		//Index of current Node within map vector
		int index = distance(map.begin(), find(map.begin(), map.end(), current));

		//If visited, exit immediately
		if (visited[index]) return;

		Node* neighbour;

		for (NodeData nD : current->GetValidAdjacentsData())
		{
			//Index of neighbour Node within map vector
			int nIndex = distance(map.begin(), find(map.begin(), map.end(), nD.node));

			neighbour = nD.node;

			//Tenatative distance
			int tDist = distances[index] + nD.cost;

			if (tDist > distances[nIndex])
			{
				distances[nIndex] = tDist;
				previous[nIndex] = nD.node;
			}
		}
		visited[index] = true;
	}

	//Attempts to find the next Node on the path
	void findNext(void)
	{
		//Current adjacent Nodes of the original current Node
		vector<NodeData> currentAdj = current->GetValidAdjacentsData();

		//Unassign current Node pointer
		current = nullptr;

		//Stores the current processed best distance (initialised as max integer value)
		int currentBestDist = INT_MAX;

		for (NodeData nP : currentAdj)
		{
			//Index of current Node within map vector
			int index = distance(map.begin(), find(map.begin(), map.end(), nP.node));

			//Checks if processed Node is closer than last
			if (distances[index] < currentBestDist && !visited[index])
			{
				current = nP.node;
				currentBestDist = distances[index];
			}
		}
		path += (current->GetName() + "\n");
	}

	virtual int heuristic(Node* n) { return INT_MAX; }

public:
	Dijkstra(void) {}
	Dijkstra(string nStart, string nEnd) {}
	using SearchAlgorithm::SearchAlgorithm;

	//Runs Dijkstra's shortest path finding algorithm and returns the path taken
	string Run(void)
	{
		path += (current->GetName() + "\n");
		distances = vector<int>(map.size());
		previous = vector<Node*>(map.size());
		for (int d : distances) d = 0;

		while (current != endRef)
		{
			calculateTentatives();
			findNext();
			if (!current) throw "There is no path to the end node!\n";
		}
		return path;
	}
};