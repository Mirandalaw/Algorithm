#include<iostream>
#include<queue>
#include<algorithm>
#define MAX 300
using namespace std;

int I,tc,answer;
int board[MAX][MAX];
int direct_x[8] = { -2,-1,1,2,2,1,-1,-2 };
int direct_y[8] = { -1,-2,-2,-1,1,2,2,1 };
int visited[MAX][MAX];
queue<pair<int, int>>q;
void init() {
	for (int col = 0; col < I; ++col) {
		for (int row = 0; row < I; ++row) {
			visited[col][row] = 0;
			board[col][row] = 0;
		}
	}
}
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 8; ++dir) {
			int nx = x + direct_x[dir];
			int ny = y + direct_y[dir];
			if (nx >= 0 && nx < I&&ny >= 0 && ny < I) {
				if (!visited[ny][nx]) {
					if (board[ny][nx] != board[y][x]) {
						board[ny][nx] = board[y][x] + 1;
						visited[ny][nx] = 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}

int main() {
	
	cin >> tc;
	for (int test_case = 0; test_case < tc; ++test_case) {
		cin >> I;
		int start_x, start_y;
		int goal_x, goal_y;
		cin >> start_x >> start_y;
		cin >> goal_x >> goal_y;
		board[start_y][start_x] = 1;
		visited[start_y][start_x] = 1;
		q.push(make_pair(start_x, start_y));
		bfs();
		answer = (board[goal_y][goal_x] - 1);
		cout << answer << endl;
		init();
	}
	return 0;
}
