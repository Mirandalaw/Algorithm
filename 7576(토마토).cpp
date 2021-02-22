#include<iostream>
#include<queue>
#define MAX 1001
using namespace std;
//1은 익은 토마토,0은 익지 않은 토마토, -1은 토마토가 들어있지 않음
int M, N;
int map[MAX][MAX];
int answer = 0;
int direct_x[4] = { 0,1,0,-1 };
int direct_y[4] = { -1,0,1,0 };
queue<pair<int, int>>q;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + direct_x[i];
			int ny = y + direct_y[i];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[ny][nx] == 0)
			{
				map[ny][nx] = map[y][x] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}


int main()
{
	cin >> M >> N;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> map[y][x];
			if (map[y][x] == 1)
			{
				q.push(make_pair(x, y));
			}
		}
	}
	bfs();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				cout << "-1" << '\n';
				return 0;
			}
			if (answer < map[i][j])answer = map[i][j];
		}
	}
	cout << (answer - 1)<<endl;
	return 0;

}