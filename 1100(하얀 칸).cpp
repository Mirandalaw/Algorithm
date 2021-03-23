#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;
void make_map();
int dx[4] = { 0,0,-1,1 };//»óÇÏÁÂ¿ì
int dy[4] = { -1,1,0,0 };//»óÇÏÁÂ¿ì
vector<vector<string>> chess_board;

int main()
{
	/*vector<string> station;
	for (int col = 0; col < 8; ++col)
	{
		for (int row = 0; row < 8; ++row)
		{
			string chess_board_station;
			cin >> chess_board_station;
			chess_board[col][row] = chess_board_station;
		}
	}*/
	make_map();
	return 0;
}

void make_map()
{
	for (int col = 0; col < 8; ++col)
	{
		for (int row = 0; row < 8; ++row)
		{
			chess_board[col][row] = "0";
		}
	}
	int start_x = 0,start_y=0;
	chess_board[0][0] = "1";
	while (start_x != 8 && start_y != 8)
	{
		start_x += 2;
		chess_board[start_y][start_x] = "1";
		start_y += 2;
		chess_board[start_y][start_x] = "1";
		start_x = next_x;
		start_y = next_y;
	}
	for (int col = 0; col < 8; ++col)
	{
		for (int row = 0; row < 8; ++row)
		{
			cout << chess_board[col][row];
		}
		cout << endl;
	}
}