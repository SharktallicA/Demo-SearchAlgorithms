#include "NodeLoader.h"
#include "BFS.h"
#include "DFS.h"
#include "Dijkstra.h"

using namespace std;

int main(void)
{
	try
	{
		NodeLoader nL("Map.txt");
		vector<Node*> map = nL.GetNodes();

		BFS bfsAl(map, "Andor", "Tau Ceti");
		string path = bfsAl.Run();
		cout << "BFS result:\n" << path << endl;

		DFS dfsAl(map, "Andor", "Tau Ceti");
		path = dfsAl.Run();
		cout << "DFS result:\n" << path << endl;

		Dijkstra dijkstraAl(map, "Andor", "Tau Ceti");
		path = dijkstraAl.Run();
		cout << "Dijkstra result:\n" << path << endl;
	}
	catch (char* msg)
	{
		cout << msg;
	}

	Utility::pause();
	return 0;
}