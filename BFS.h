#pragma once
#include "Algorithm.h"

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