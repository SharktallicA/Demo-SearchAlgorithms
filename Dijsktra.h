#pragma once
#include "Algorithm.h"

//Dijsktra's shortest path finding algorithm implementation
class Dijsktra : public Algorithm
{
private:

	//Processes the distances between neighbouring Nodes to the current Node
	void calculateTenatatives(void)
	{
		//Index of current Node within map vector
		int index = distance(map.begin(), find(map.begin(), map.end(), current));

		//If visited, exit immediately
		if (visited[index]) return;

		int distance;
		Node* neighbour;

		for (NodeData nD : current->GetValidAdjacentsData())
		{
			neighbour = nD.node;

		}
		visited[index] = true;
	}

public:
	Dijsktra(string nStart, string nEnd) {}
	using Algorithm::Algorithm;

	//Runs Dijsktra's shortest path finding algorithm and returns the path taken
	string Run(void)
	{

		while (current != endRef)
		{

		}

		return "";
	}
};