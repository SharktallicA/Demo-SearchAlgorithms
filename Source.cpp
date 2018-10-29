#include "NodeLoader.h"
#include "BFS.h"
#include "DFS.h"

using namespace std;

int main(void)
{
	NodeLoader nL("Map.txt");
	vector<Node*> map = nL.GetNodes();

	BFS bfsAl(map, "Andor", "Tau Ceti");
	string path = bfsAl.Run();
	cout << "BFS result:\n" << path << endl;

	DFS dfsAl(map, "Andor", "Tau Ceti");
	path = dfsAl.Run();
	cout << "DFS result:\n" << path << endl;

	Utility::pause();

	return 0;
}