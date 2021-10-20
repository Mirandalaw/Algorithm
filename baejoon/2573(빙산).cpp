#include<iostream>
#include<queue>
#define MAX 300
using namespace std;

int n, m;
int ice[MAX][MAX];
int meltIce[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void bfs(int start_x, int start_y) {
	queue<pair<int, int>>q;
	q.push(make_pair(start_x, start_y));
	visited[start_y][start_x] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && nx < m&&ny >= 0 && ny < n&&ice[ny][nx] == 0) {
				meltIce[y][x]--;
			}
			else if (nx >= 0 & nx < m&&ny >= 0 && ny < n&&ice[ny][nx] != 0 && !visited[ny][nx]) {
				q.push(make_pair(nx, ny));
				visited[ny][nx] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int col = 0; col < n; ++col) {
		for (int row = 0; row < m; ++row) {
			cin >> ice[col][row];
			if (ice[col][row] == 0)visited[col][row] = true;
			meltIce[col][row] = ice[col][row];
		}
	}
	int answer = 0;

	while (1) {
		int cnt = 0;
		for (int col = 0; col < n; ++col) {
			for (int row = 0; row < m; ++row) {
				if (!visited[col][row]) {
					bfs(row, col);
					cnt++;
				}
			}
		}
		if (cnt == 0) {
			cout << 0 << endl;
			break;
		}
		if (cnt >= 2) {
			cout << answer;
			break;
		}
		for (int col = 0; col < n; ++col) {
			for (int row = 0; row < m; ++row) {
				if (meltIce[col][row] < 0)meltIce[col][row] = 0;
			}
		}
		for (int col = 0; col < n; ++col) {
			for (int row = 0; row < m; ++row) {
				ice[col][row] = meltIce[col][row];
			}
		}
		for (int col = 0; col < n; ++col) {
			for (int row = 0; row < m; ++row) {
				if (ice[col][row] == 0)visited[col][row] = true;
				else visited[col][row] = false;
				meltIce[col][row] = ice[col][row];
			}
		}
		answer++;
	}
	return 0;
}
