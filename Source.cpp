#include "NodeLoader.h"
#include "Algorithm.h"

using namespace std;

int main(void)
{
	NodeLoader nL("Map.txt");

	BFS bfsAl(nL.GetNodes(), "Sol", "Tau Ceti");
	string path = bfsAl.Run();
	cout << path << endl;

	Utility::pause();

	return 0;
}