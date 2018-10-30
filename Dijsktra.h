#pragma once
#include "Algorithm.h"

//Dijsktra's shortest path finding algorithm implementation
class Dijsktra : public Algorithm
{
private:
	vector<int> distances;

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

			if (tDist < distances[nIndex])
			{
				distances[nIndex] = tDist;
				previous[nIndex] = nD.node;
			}
		}
		visited[index] = true;
	}

	void findNext(void)
	{
		int currentBestDist = 0;

		for (int i = 0; i < current->GetValidAdjacentsData().size(); i++)
		{
			
		}
	}

public:
	Dijsktra(string nStart, string nEnd) {}
	using Algorithm::Algorithm;

	//Runs Dijsktra's shortest path finding algorithm and returns the path taken
	string Run(void)
	{
		distances = vector<int>(map.size());
		for (int d : distances) d = 0;

		while (current != endRef)
		{
			calculateTentatives();
		}

		return "";
	}
};