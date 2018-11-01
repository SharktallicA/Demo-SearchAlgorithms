#pragma once
#include "SearchAlgorithm.h"

//Depth-First Search algorithm implementation
class DFS : public SearchAlgorithm
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
		vector<Node*> adjacents = nP->GetAdjacents();

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
	DFS(string nStart, string nEnd) {}
	using SearchAlgorithm::SearchAlgorithm;

	//Runs Depth-First search algorithm and returns the path taken
	string Run(void)
	{
		Recur(startRef);
		return path;
	}
};