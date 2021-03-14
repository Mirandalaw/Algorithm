#include<iostream>
#include<queue>
#define MAX 51
using namespace std;

int dx[4] = {1,0,-1,0};//우하좌상
int dy[4] = {0,1,0,-1};//우하좌상

void bfs(int start_x, int start_y,int map[MAX][MAX],bool visited[MAX][MAX],int r,int c)
{
	queue<pair<int, int>> q;
	q.push(make_pair(start_x, start_y));
	visited[start_y][start_x] = true;

	while (!q.empty())
	{
		start_x = q.front().first;
		start_y = q.front().second;
		q.pop();
		
		for (int direct = 0; direct < 4; ++direct)
		{
			int next_x = start_x + dx[direct];
			int next_y = start_y + dy[direct];
			if (0 <= next_x && next_x < r && 0 <= next_y && next_y < c)
			{
				if (map[next_y][next_x] == 1 && visited[next_y][next_x] == false)
				{
					q.push(make_pair(next_x, next_y));
					visited[next_y][next_x] = true;
				}
			}
		}
	}

}
int main()
{
	int test_case;
	cin >> test_case;
	for (int tc = 0; tc < test_case; ++tc)
	{
		int r, c, k,earthworms=0;//가로 세로 개수
		int map[MAX][MAX] = { 0 };
		bool visited[MAX][MAX] = { 0 };
		cin >> r >> c >> k;
		for (int number = 0; number < k; ++number)
		{
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}
		for (int col = 0; col < c; ++col)
		{
			for (int row = 0; row < r; ++row)
			{
				if (visited[col][row] == false && map[col][row] == 1)
				{
					earthworms++;
					bfs(row, col, map, visited, r, c);
				}
			}
		}
		cout << earthworms << endl;
	}
	return 0;
}