#include<iostream>
#include<queue>
#define MAX 51
using namespace std;

int w, h;
int direct_x[8] = { -1,-1,-1,0,1,1,1,0 };
int direct_y[8] = { 1,0,-1,-1,-1,0,1,1 };

int island[MAX][MAX];
bool visited[MAX][MAX];
int answer = 0;


void init() {
	for (int col = 0; col < h; ++col) {
		for (int row = 0; row < w; ++row) {
			island[col][row] = 0;
			visited[col][row] = false;
		}
	}
}
void bfs(int start_x, int start_y) {
	queue<pair<int, int>>q;
	visited[start_y][start_x] = true;
	q.push(make_pair(start_x, start_y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 8; ++dir) {
			int next_x = x + direct_x[dir];
			int next_y = y + direct_y[dir];
			if (next_x >= 0 && next_x < w && next_y >= 0 && next_y < h&&visited[next_y][next_x]==false&&island[next_y][next_x]==1) {
				visited[next_y][next_x] = true;
				q.push(make_pair(next_x, next_y));
			}
		}
	}
}
int main() {
	int stop_button = 1;
	while (stop_button) {
		init();
		answer = 0;
		cin >> w >> h;
		if (w == 0 && h == 0)return 0;
		for (int col = 0; col < h; ++col) {
			for (int row = 0; row < w; ++row) {
				cin >> island[col][row];
				if (island[col][row] == 1)visited[col][row] = false;
				else visited[col][row] = true;
			}
		}
		for (int col = 0; col < h; ++col) {
			for (int row = 0; row < w; ++ row) {
				if (visited[col][row] == false) {
					bfs(row, col);
					answer++;
				}
			}
		}
		cout << answer << "\n";
	}
}
