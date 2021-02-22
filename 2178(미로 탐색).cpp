#include<iostream>
#include<queue>
#include<utility>
#define MAX 101
using namespace std;

int N, M;
int map[MAX][MAX];
int direct[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };//상하좌우 방향성
queue<pair<int, int>> q;
void bfs()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	q.push(make_pair(0, 0));//시작점(0,0)에서 출발하여 (N-1,M-1)에 도착,
	pair<int, int>current;
	int nx, ny;
	while (!q.empty())
	{
		current = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			nx = current.second + direct[i][0];//다음 x의 방향
			ny = current.first + direct[i][1];//다음 y의 방향
			if (0 <= nx && nx < M && 0 <= ny && ny < N && map[ny][nx] == 1)
			{
				q.push(make_pair(ny, nx));
				map[ny][nx] = map[current.first][current.second] + 1;
			}
		}
	}
	return;
}

int main()
{
	cin >> N >> M;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			scanf_s("%1d", &map[y][x]);
		}
	}
	bfs();
	cout << map[N - 1][M - 1];
}
//#include<iostream>
//#include<queue>
//#define MAX 101
//using namespace std;
//
//int arr[MAX][MAX];
//int dist[MAX][MAX] = { 0 };//방문햇는지 안햇는ㄷ지
//int answer;
//int N, M;
//queue<pair<int, int>>q;//좌표축 자체를 que에
//
//int dx[4] = { 0,1,0,-1 };//하우상좌
//int dy[4] = { 1,0,-1,0 };//하우상좌
//
//void bfs(int a, int b)
//{
//	q.push(make_pair(a, b));
//	dist[a][b]++;
//	while (!q.empty())
//	{
//		int x = q.front().first;
//		int y = q.front().second;
//		q.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//
//			if (nx <= 0 || nx > N || ny <= 0 || ny > M)continue;
//			if (dist[nx][ny] == 0 && arr[nx][ny] == 1)
//			{
//				dist[nx][ny] = dist[x][y] + 1;
//				q.push(make_pair(nx, ny));
//			}
//		}
//	}
//}
//int main()
//{
//	cin >> N >> M;
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= M; j++)
//		{
//			scanf_s("%1d", &arr[i][j]);
//		}
//	}
//	bfs(1, 1);
//	cout << dist[N][M] << '\n';
//	return 0;
//}