#include<iostream>
#include<queue>
#define MAX 1001
using namespace std;

int box[MAX][MAX];
int N, M;
queue<pair<int, int>> q;
int answer = 0;
int direct_x[4] = { 0,1,0,-1 };
int direct_y[4] = { -1,0,1,0 };
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int next_x = x + direct_x[dir];
			int next_y = y + direct_y[dir];
			if (next_x >= 0 && next_x < M&&next_y >= 0 && next_y < N&&box[next_y][next_x] == 0) {
				box[next_y][next_x] = box[y][x] + 1;
				q.push(make_pair(next_x, next_y));
			}
		}
	}
}
int main() {
	cin >> M >> N;
	for (int col = 0; col < N; ++col) {
		for (int row = 0; row < M; ++row) {
			cin >> box[col][row];
			if (box[col][row] == 1)q.push(make_pair(row, col));
		}
	}
	
	bfs();
	
	for (int col = 0; col < N; ++col) {
		for (int row = 0; row < M; ++row) {
			if (box[col][row] == 0) {
				cout << "-1" << '\n';
				return 0;
			}
			if (box[col][row] > answer)answer = box[col][row];
		}
	}
	cout << answer - 1 << endl;
	return 0;
}
