#pragma once
#include "Dijkstra.h"

//A* shortest path finding algorithm implementation
class AStar : public Dijkstra
{
private:
	//A*'s heuristic function that builds upon Dijkstra's algorithm
	int heuristic(Node* n)
	{
		return 0;
	}

public:
	AStar(string nStart, string nEnd) {}
	using Dijkstra::Dijkstra;
};