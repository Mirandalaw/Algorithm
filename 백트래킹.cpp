#include<iostream>
using namespace std;

int maps[10][10];
int visited[10] = { 0 };
int num;

void init() {
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			maps[i][j] = 0;
		}
	}
}
void dfs(int v)
{
	cout << v << endl;
	visited[v] = 0;
	for (int i = 0; i <= num; i++)
	{
		if (maps[v][i] && visited[i]) dfs(i);

	}
}
int main()
{
	int v1, v2;
	init();
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> v1 >> v2;
		maps[v1][v2] = maps[v2][v1] = 1;
		visited[v1] = visited[v2] = 1;
	}
	dfs(1);

	return 0;
}