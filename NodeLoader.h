#pragma once
#include "Node.h"
#include <fstream>

using namespace std;

class NodeLoader
{
private:
	string fileName;

	//Loads the raw Node name and placement data from Map text file
	vector<vector<string>> loadNodes(void)
	{
		ifstream ifMap(fileName);
		if (!ifMap) throw "CRITICAL ERROR: Map.txt data file is not present!\n";

		vector<vector<string>> rawNodes;
		string line;

		while (getline(ifMap, line))
		{
			vector<string> delimited;
			stringstream pStream(line);
			
			if (line[0] != '#') //prevent operation for any comment or metadata lines within the text file
			{
				while (pStream.good())
				{
					string sub;
					getline(pStream, sub, ',');
					delimited.push_back(sub);
				}
				rawNodes.push_back(delimited);
			}
		}
		ifMap.close();
		return rawNodes;
	}

public:
	NodeLoader(string nFileName) { fileName = nFileName; }

	//Constructs the Node map as doubly-linked list of Node objects from raw Node data
	vector<Node*> GetNodes(void)
	{
		// 1) Attempts to call for the loading of the Node map data text file
		// and get the result returned for processing

		vector<vector<string>> raw;
		try { raw = loadNodes(); }
		catch (char* msg) { throw msg; }

		// 2) Constructs a vector of Node objects from the raw data, using
		// the place name at this point (all Nodes will have to be created before mapping adjacents)

		vector<Node*> map;
		for (vector<string> rawPlace : raw) map.push_back(new Node(rawPlace[0]));

		// 3) Maps out the relative (up, right, down, left) adjacent nodes
		// for each Node object; for each Node object in map vector, use the raw
		// Node map data to find out the names of its neighbours and then link
		// their Node objects into the current one (and repeat) until (an up to
		// four-way) doubly-linked list is formed

		for (unsigned int i = 0; i < map.size(); i++)
		{
			vector<Node*> relatives;

			//find and get the Node object adjacent to the current one
			for (int j = 1; j <= 4; j++)
			{
				if (raw[i][j] != "-") //work out the relative Node if one is specified in the raw data
				{
					for (Node* node : map) if (node->GetName() == raw[i][j]) relatives.push_back(node);
				}
				else relatives.push_back(nullptr); //nullptr to represent blank wall
			}

			//call for the mapping of the places to form the linked bonds
			map[i]->MapRelativies(NodeData(relatives[0], stoi(raw[i][5])), NodeData(relatives[1], stoi(raw[i][6])), NodeData(relatives[2], stoi(raw[i][7])), NodeData(relatives[3], stoi(raw[i][8])));
		}

		// 4) Return the end result
		return map;
	}
};