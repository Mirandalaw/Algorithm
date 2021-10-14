#include<iostream>
#include<queue>
#define MAX 51

using namespace std;

int direct_x[4] = { 0,1,0,-1 };
int direct_y[4] = { -1,0,1,0 };
int field[MAX][MAX];
int visited[MAX][MAX];
int tc, M, N,K;

void bfs(int start_x, int start_y) {
	queue<pair<int, int>>q;
	q.push(make_pair(start_x, start_y));
	visited[start_y][start_x] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int next_x = x + direct_x[dir];
			int next_y = y + direct_y[dir];
			if (next_x >= 0 && next_x < M&&next_y >= 0 && next_y < N&&visited[next_y][next_x] == 1 && field[next_y][next_x] == 1) {
				visited[next_y][next_x] = 0;
				q.push(make_pair(next_x, next_y));
			}
		}
	}
}
void init() {
	for (int col = 0; col < N; ++col) {
		for (int row = 0; row < M; ++row) {
			field[col][row] = 0;
			visited[col][row] = 0;
		}
	}
}
int main() {
	cin >> tc;
	for (int test_case = 0; test_case < tc; ++test_case) {

		int answer = 0;
		cin >> M >> N >> K;
		init();
		for (int num = 0; num < K; ++num) {
			int x, y;
			cin >> x >> y;
			field[y][x] = 1;
			if (field[y][x] == 1)visited[y][x] = 1;
		}
		/*for (int col = 0; col < N; ++col) {
			for (int row = 0; row < M; ++row) {
				cout << field[col][row];
			}
			cout << endl;
		}*/

		for (int col = 0; col < N; ++col) {
			for (int row = 0; row < M; ++row) {
				if (visited[col][row] == 1) {
					bfs(row, col);
					answer++;
				}
			}
		}
		cout << answer << "\n";
	}
	return 0;
}
