#include<iostream>
#include<queue>
#include<algorithm>
#define MAX 25

using namespace std;

int num_of_houses[MAX * MAX] = { 0, };
int house_number = 0;
int N, map[MAX][MAX],visited[MAX][MAX];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int start_x, int start_y);
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
			if (map[col][row] == 1 && visited[col][row] == 1)
			{
				house_number++;
				bfs(col, row);
			}
		}
	}
	sort(num_of_houses + 1, num_of_houses + house_number + 1);
	
	cout << house_number<<endl;
	
	for (int i = 1; i <= house_number; ++i)
	{
		cout << num_of_houses[i]<<endl;
	}
	return 0;
}
void bfs(int start_y, int start_x)
{
	queue<pair<int,int>> q;
	q.push(pair<int,int>(start_y, start_x));//q.push(pair<int,int>(r,c));  == 같은의미 q.push(make_pair(r,c))
	visited[start_y][start_x] = 1;
	num_of_houses[house_number]++;

	while (!q.empty())
	{
		start_y = q.front().first;
		start_x = q.front().second;
		q.pop();
		//해당 위치의 주변을 확인
		for (int i = 0; i < 4; ++i)
		{
			int next_x = start_x + dx[i];
			int next_y = start_y + dy[i];
			if (0 <= next_x && next_x < N && 0 <= next_y && next_y < N)
			{
				if (map[next_y][next_x] == 1 && visited[next_y][next_x] == 0)
				{
					visited[next_y][next_x] = 1;
					num_of_houses[house_number]++;
					q.push(pair<int,int>(next_y, next_x));
				}
			}
		}
	}
}