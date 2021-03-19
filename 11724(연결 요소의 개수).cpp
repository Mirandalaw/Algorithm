#include<iostream>
#include<queue>
#define MAX 1001
using namespace std;

void bfs(int start);
int N, M;
int map[MAX][MAX] = { 0 };
bool visited[MAX] = { 0 };
int main()
{
	cin >> N >> M;
	for (int edge_number = 0; edge_number < M; edge_number++)
	{
		int start_edge, end_edge;
		cin >> start_edge >> end_edge;
		map[start_edge][end_edge] = map[end_edge][start_edge] = 1;
	}
	int cnt = 1;
	bfs(1);
	for (int i = 1; i <= N; ++i)
	{
		if (!visited[i] != false)
		{
			cnt++;
			bfs(i);
		}
	}
	cout << cnt;
	return 0;
}

void bfs(int start)
{
	queue<int> q;

	visited[start] = true;
	q.push(start);
	
	while (!q.empty())
	{
		start = q.front();
		q.pop();

		for (int col = 1; col <= N; ++col)
		{
			if (map[start][col] == 1 && visited[col] == false)
			{
				q.push(col);
				visited[col] = true;
			}
		}
	}
}