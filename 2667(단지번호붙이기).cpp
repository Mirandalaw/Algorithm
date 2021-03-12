#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
#define MAX_SIZE 25
using namespace std;

void bfs(int start_x, int start_y);
int N;
int house_number = 0, house[MAX_SIZE * MAX_SIZE] = { 0 };//집의 크기

int map[MAX_SIZE][MAX_SIZE] = { 0 };
int visited[MAX_SIZE][MAX_SIZE] = { 0 };

int dx[4] = { 1,0,-1,0 };//우하좌상
int dy[4] = { 0,1,0,-1 };//우하좌상
int main()
{
	cin >> N;
	for (int col = 0; col < N; ++col)
	{
		for (int row = 0; row < N; ++row)
		{
			scanf_s("%1d", &map[col][row]);
		}
	}
	for (int col = 0; col < N; ++col)
	{
		for (int row = 0; row < N; ++row)
		{
			if (map[col][row] == 1 && visited[col][row] == 0)
			{
				house_number++;
				bfs(col, row);
				
			}
		}
	}
	sort(house+1, house + house_number+1);
	cout << house_number << endl;
	for (int i = 1; i <= house_number; i++)
	{
		cout << house[i] << endl;
	}
	return 0;
}
void bfs(int start_y, int start_x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(start_y, start_x));

	visited[start_y][start_x]=1;
	house[house_number]++;

	while (!q.empty())
	{
		start_y = q.front().first;
		start_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = start_x + dx[i];
			int next_y = start_y + dy[i];
			if (0 <= next_x && next_x < N && 0 <= next_y && next_y < N)
			{
				if (visited[next_y][next_x] == 0 && map[next_y][next_x] == 1)
				{
					visited[next_y][next_x] = 1;
					house[house_number]++;
					q.push(make_pair(next_y, next_x));
				}
			}
		}
	}
}