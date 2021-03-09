#include<iostream>
#include<vector>
#include<queue>
#define MAX 30+1
using namespace std;
void init(int graph[MAX][MAX], int n);
void init_visited(int visited[MAX], int n);
void print(int graph[MAX][MAX], int n);
void dfs(int visited[MAX],int graph[MAX][MAX],int v,int n);
void bfs(int visited[MAX], int graph[MAX][MAX], int v, int n);
vector<int> dfs_st;
vector<int> bfs_st;
int main()
{
	int n, m,v;//정점의 수와 간선의 수와 정점의 번호
	int graph[MAX][MAX];
	int visited[MAX];
	cin >> n >> m >> v;
	init(graph,n);
	init_visited(visited, n);
	int count = 0;
	while (count!=m)
	{
		int number_of_vertex1, number_of_vertex2;
		cin >> number_of_vertex1 >> number_of_vertex2;
		graph[number_of_vertex1][number_of_vertex2] = graph[number_of_vertex2][number_of_vertex1] = 1;
		count++;
	}
	print(graph, n);
	dfs(visited, graph, v, n);
	init_visited(visited, n);
	bfs(visited, graph, v, n);
	for (int i = 0; i < dfs_st.size(); i++)
	{
		printf("%d", dfs_st[i]);
	}
	printf("\n");
	for (int i = 0; i < bfs_st.size(); i++)
	{
		printf("%d", bfs_st[i]);
	}
	return 0;
}
void init(int graph[MAX][MAX],int n)
{
	for (int row = 1; row <= n; ++row)
	{
		for (int col = 1; col <= n; ++col)
		{
			graph[row][col] = 0;
		}
	}
}
void init_visited(int visited[MAX], int n)//1이면 방문하지 않았음으로 초기화 해줌
{
	for (int row = 1; row <= n; row++)
	{
		visited[row] = 0;
	}
}
void print(int graph[MAX][MAX], int n)
{
	for (int row = 1; row <= n; ++row)
	{
		for (int col = 1; col <= n; ++col)
		{
			printf("%d", graph[row][col]);
		}
		printf("\n");
	}
	printf("\n");
}
void dfs(int visited[MAX],int graph[MAX][MAX],int v,int n)
{
	int start_vertex = v;
	visited[v] = 1;
	dfs_st.push_back(start_vertex);
	for (int i = 1; i <= n; ++i )
	{
		if (graph[start_vertex][i] == 1&&visited[i]!=1)
		{
			visited[start_vertex]= 1;
			dfs(visited, graph, i, n);
		}
	}
}
void bfs(int visited[MAX],int graph[MAX][MAX],int v,int n)
{
	queue<int> bfs_start;
	int start_vertex = v;
	bfs_start.push(start_vertex);
	visited[start_vertex] = 1;

	while (!bfs_start.empty())
	{
		int current = bfs_start.front();
		bfs_start.pop();
		bfs_st.push_back(current);

		for (int i = 1; i <= n; i++)
		{
			if (graph[current][i] == 1 && visited[i] != 1)
			{
				bfs_start.push(i);
				visited[i] = 1;
			}
		}
	}
}
