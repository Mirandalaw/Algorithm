#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int dx[4] = { 0,0,-1,1 };//상하좌우
int dy[4] = { -1,1,0,0 };//상하좌우
string chess_board[8][8];

void bfs(int start_x, int start_y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(start_x, start_y));

	while (!q.empty())
	{
		start_x = q.front().first;
		start_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int next_x = start_x + dx[i];
			int next_y = start_y + dy[i];
			if (0 <= next_x && next_x < 8 && 0 <= next_y && next_y < 8)
			{
				if (chess_board[next_y][next_x] == chess_board[start_y][start_x])
				{
					if (chess_board[start_y][start_x] == "1") chess_board[next_y][next_x] = "0";
					else if (chess_board[start_y][start_x] == "0")chess_board[next_y][next_x] = "1";
				}
			}
		}
	}
}
void make_map()
{
	chess_board[0][0] = "1";
	for (int col = 0; col < 8; ++col)
	{
		for (int row = 0; row < 8; ++row)
		{
			bfs(row, col);
		}
	}
}

int main()
{
	for (int col = 0; col < 8; ++col)
	{
		for (int row = 0; row < 8; ++row)
		{
			chess_board[col][row] = "0";
		}
	}
	make_map();
	string push_chess_board[8];
	for (int col = 0; col < 8; ++col)
	{
		cin >> push_chess_board[col];
	}
	int result_cnt = 0;
	for (int col = 0; col < 8; ++col)
	{
		for (int row = 0; row < 8; ++row)
		{
			if (chess_board[col][row] == "1" && push_chess_board[col].substr(row, 1) == "F")result_cnt++;
		}
	}
	cout << result_cnt;
	
	return 0;
}
