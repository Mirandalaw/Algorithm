//#include<iostream>
//#include<queue>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int dx[4] = { 0,0,-1,1 };//상하좌우
//int dy[4] = { -1,1,0,0 };//상하좌우
//
//int main()
//{
//	int N, M;
//	cin >> N >> M;
//
//	vector<vector<int>> v(N, vector<int>(M));//세로줄 N개,가로줄 M개
//
//	for (int col = 0; col < N; ++col)
//	{
//		for (int row = 0; row < M; ++row)
//		{
//			int map_information;
//			cin >> map_information;
//			v[col][row] = map_information;
//		}
//	}
//	/*for (int col = 0; col < N; ++col)
//	{
//		for (int row = 0; row < M; ++row)
//		{
//			cout << v[col][row];
//		}
//		cout << endl;
//	}*/
//	return 0;
//}

#include<iostream>
#include<queue>
#include<algorithm>
#define MAX 10
using namespace std;

int map[MAX][MAX] = { 0 };
int temp[MAX][MAX] = { 0 };
int dx[4] = { 0,0,1,-1 };//상하우좌;
int dy[4] = { -1,1,0,0 };//상하우좌;
int N, M, area;
void make_wall(int wall);
void bfs();

int main()
{
	cin >> N >> M;
	for (int col = 0; col < N; ++col)
	{
		for (int row = 0; row < M; ++row)
		{
			cin >> map[col][row];
		}
	}
	for (int col = 0; col < N; ++col)
	{
		for (int row = 0; row < M; ++row)
		{
			if (map[col][row] == 0)
			{
				for (int i = 0; i < N; ++i)
				{
					for (int j = 0; j < M; ++j)
					{
						temp[i][j] = map[i][j];
					}
				}
				temp[col][row] = 1;
				make_wall(1);
				//다시 원상복구
				temp[col][row] = 0;
			}
		}
	}
	cout << area << endl;
}
void make_wall(int wall)
{
	//벽3개만들기!
	if (wall == 3)
	{
		bfs();
		return;
	}
	for (int col = 0; col < N; ++col)
	{
		for (int row = 0; row < M; ++row)
		{
			if (temp[col][row] == 0)
			{
				temp[col][row] = 1;
				make_wall(wall + 1);//벽을 한칸 늘림
				temp[col][row] = 0;// 다시 0으로 돌려주기
			}
		}
	}
}
void bfs()
{
	int virus[MAX][MAX] = { 0 };
	for (int col = 0; col < N; ++col)
	{
		for (int row = 0; row < M; ++row)
		{
			virus[col][row] = temp[col][row];
		}
	}
	queue<pair<int, int>>q;
	for (int col = 0; col < N; ++col)
	{
		for (int row = 0; row < M; ++row)
		{
			if (virus[col][row] == 2)
			{
				q.push(make_pair(row, col));//바이러스좌표를 저장
			}
		}
	}
	while (!q.empty())//바이러스의 위치값이 저장되어있음
	{
		int start_x = q.front().first;
		int start_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_x = start_x + dx[i];
			int next_y = start_y + dy[i];
			if (0 <= next_x && next_x < M && 0 <= next_y && next_y < N)
			{
				if (virus[next_y][next_x] == 0)//벽으로 막혀있지 않으면 퍼짐
				{
					virus[next_y][next_x] = 2;
					q.push(make_pair(next_x, next_y));
				}
			}
		}
	}
	int cnt = 0;
	for (int col = 0; col < N; ++col)//안전영역의 값
	{
		for (int row = 0; row < M; ++row)
		{
			if (virus[col][row] == 0)
			{
				cnt++;
			}
		}
	}
	area = max(area, cnt);
}