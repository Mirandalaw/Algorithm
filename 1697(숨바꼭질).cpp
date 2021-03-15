#include<iostream>
#include<queue>
#include<string>
#define MAX 100001
using namespace std;
int bfs(int N, int K);
bool visited[MAX];
int main()
{
	int N, K;
	cin >> N >> K;
	cout << bfs(N, K) << endl;
	return 0;
}
int bfs(int N, int K)
{
	queue<pair<int, int>>q;
	q.push(make_pair(N, 0));
	visited[N] = true;

	while (!q.empty())
	{
		int Line = q.front().first;
		int time = q.front().second;
		q.pop();

		if (Line == K)return time;

		if (Line + 1 < MAX && !visited[Line + 1])
		{
			q.push(make_pair(Line + 1, time + 1));
			visited[Line + 1] = true;
		}
		if (Line - 1 >= 0 && !visited[Line - 1])
		{
			q.push(make_pair(Line - 1, time + 1));
			visited[Line - 1] = true;
		}
		if (Line * 2 < MAX && !visited[Line * 2])
		{
			q.push(make_pair(Line * 2, time + 1));
			visited[Line * 2] = true;
		}
	}
}