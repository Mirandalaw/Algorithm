#include<iostream>
#include<queue>
#include<vector>
#define MAX 101
using namespace std;

int cnt = 0;

void bfs(int network[MAX][MAX], int visited[MAX], int number_of_computer, int start_vertex);
int main()
{
	int network[MAX][MAX] = { 0 };
	int visited[MAX] = { 0 };
	int number_of_computer;
	int link_of_computer;

	cin >> number_of_computer;//정점
	cin >> link_of_computer;//간선

	for (int col = 1; col <= link_of_computer; ++col)
	{
		int start_edge, end_edge;
		cin >> start_edge >> end_edge;
		network[start_edge][end_edge] = network[end_edge][start_edge] = 1;
	}
	bfs(network, visited, number_of_computer, 1);
	cout << cnt;
	return 0;
}

void bfs(int network[MAX][MAX], int visited[MAX], int number_of_computer, int start_vertex)
{	
	int s_vertex = start_vertex;
	visited[s_vertex] = 1;
	queue<int> bfs_storage;
	bfs_storage.push(s_vertex);
	
	while (!bfs_storage.empty())
	{
		int current = bfs_storage.front();
		bfs_storage.pop();
		for (int col = 1; col <= number_of_computer; ++col)
		{
			if (network[current][col] == 1 && visited[col] != 1)
			{
				bfs_storage.push(col);
				visited[col] = 1;
				cnt++;
			}
		}
	}
}