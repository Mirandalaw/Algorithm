#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

vector<int>dfs_order;
vector<int>bfs_order;
vector<bool>visited;

int map[1001][1001];

int V, E;
void dfs(int current)
{
	visited[current] = true;
	dfs_order.push_back(current);
	for (int to = 1; to <= V; to++)
	{
		if (!visited[to] && map[current][to] == 1) dfs(to);
	}
}
void bfs(int start)
{
	queue<int> q;
	q.push(start);
	bfs_order.push_back(start);
	visited[start] = true;

	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		for (int next = 1; next <= V; next++)
		{
			if (!visited[next] && map[current][next] == 1)
			{
				q.push(next);
				bfs_order.push_back(next);
				visited[next] = true;
			}
		}
	}
}
void print_order(vector<int>& order)
{
	for (int i = 0; i < order.size(); i++)
	{
		printf("%d ", order[i]);
	}
	printf("\n");
}
int main()
{
	cin >> V >> E;
	int start;
	cin >> start;
	for (int i = 0; i < E; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1; //2차원 그래프에 입력된 간선 찍어주기
	}
	visited = vector<bool>(V + 1);//V+1까지 0으로 초기화
	dfs(start);
	visited = vector<bool>(V + 1);//V+1까지 0으로 초기화
	bfs(start);

	print_order(dfs_order);
	print_order(bfs_order);

	return 0;
}