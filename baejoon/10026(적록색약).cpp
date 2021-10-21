#include<iostream>
#include<queue>
#include<string>
#define MAX 101
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
char greed[MAX][MAX];
int visited[MAX][MAX];
int N;
int answer = 0;
int answer1 = 0;
void bfs(int start_x, int start_y) {
	queue<pair<int, int>>q;
	q.push(make_pair(start_x, start_y));
	visited[start_y][start_x] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && ny >= 0 && nx < N&&ny < N) {
				if (visited[ny][nx] == 0) {
					if (greed[ny][nx] == greed[y][x]) {
						visited[ny][nx] = 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}
int main() {
	cin >> N;
	for (int col = 0; col < N; ++col) {
		for (int row = 0; row < N; ++row) {
			cin >> greed[col][row];
		}
	}
	for (int col = 0; col < N; ++col) {
		for (int row = 0; row < N; ++row) {
			if (!visited[col][row]) {
				bfs(row, col);
				answer++;
			}
		}
	}
	memset(visited, 0, sizeof(visited));
	for (int col = 0; col < N; ++col) {
		for (int row = 0; row < N; ++row) {
			if (greed[col][row] == 'G')greed[col][row] = 'R';
		}
	}
	for (int col = 0; col < N; ++col) {
		for (int row = 0; row < N; ++row) {
			if (visited[col][row] == 0) {
				bfs(row, col);
				answer1++;
			}
		}
	}
	cout << answer << " " << answer1 << endl;
	return 0;
}
