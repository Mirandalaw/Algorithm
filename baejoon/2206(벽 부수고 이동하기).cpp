#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

#define MAX 1001
using namespace std;

int N, M;
int map[MAX][MAX];
int noWallMap[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
vector<int>answer;

void init() {
	for (int col = 0; col < N; ++col) {
		for (int row = 0; row < M; ++row) {
			visited[col][row] = 0;
		}
	}
}
void bfs(int start_x,int start_y) {

	for (int col = 0; col < N; ++col) {
		for (int row = 0; row < M; ++row) {
			map[col][row] = noWallMap[col][row];
		}
	}
	queue<pair<int, int>>q;
	q.push(make_pair(start_x, start_y));
	visited[start_y][start_x] = 1;
	noWallMap[start_y][start_x] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = dx[dir] + x;
			int ny = dy[dir] + y;
			if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
				if (!visited[ny][nx]) {
					if (noWallMap[ny][nx] == 0) {
						noWallMap[ny][nx] = noWallMap[y][x] + 1;
						visited[ny][nx] = 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
	if (noWallMap[N - 1][M - 1] != 0)answer.push_back(noWallMap[N - 1][M - 1]);
	for (int col = 0; col < N; ++col) {
		for (int row = 0; row < M; ++row) {
			noWallMap[col][row] = map[col][row];
		}
	}
	init();
}

void breakWall(int cnt) {
	if (cnt == 1) {
		bfs(0,0);
		return;
	}
	for (int col = 0; col < N; ++col) {
		for (int row = 0; row < M; ++row) {
			if (noWallMap[col][row] == 1) {
				noWallMap[col][row] = 0;
				breakWall(cnt + 1);
				noWallMap[col][row] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int col = 0; col < N; ++col) {
		for (int row = 0; row < M; ++row) {
			scanf_s("%1d", &map[col][row]);
			if (map[col][row] == 1)noWallMap[col][row] = 1;
		}
	}
	breakWall(0);
	if (answer.size() == 0)cout << -1;
	else {
		sort(answer.begin(), answer.end());
		cout << answer[0];
	}
	return 0;
}
