#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAX 9
using namespace std;
int N, M;
int lab[MAX][MAX];
int wall[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int result;
queue<pair<int, int>>q;


void show() {
	cout << endl;
	for (int col = 0; col < N; ++col) {
		for (int row = 0; row < M; ++row) {
			cout << wall[col][row] << " ";
		}
		cout << endl;
	}
}
void spreadVirus() {
	int labVirus[MAX][MAX];
	for (int col = 0; col < N; ++col) {
		for (int row = 0; row < M; ++row) {
			labVirus[col][row] = wall[col][row];
			if (labVirus[col][row] == 2) {
				q.push(make_pair(row, col));
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {

				if (labVirus[y][x] == 2 && labVirus[ny][nx] == 0) {
					labVirus[ny][nx] = 2;
					q.push(make_pair(nx, ny));

				}
			}
		}
	}
	int safeArea = 0;
	for (int col = 0; col < N; ++col) {
		for (int row = 0; row < M; ++row) {
			if (labVirus[col][row] == 0) {
				safeArea++;
			}
		}
	}
	result = max(safeArea, result);
	/*for (int col = 0; col < N; ++col) {
		for (int row = 0; row < M; ++row) {
			lab[col][row] = labVirus[col][row];
		}
	}*/
}
void makeWall(int cnt) {
	if (cnt == 3) {
		spreadVirus();
		return;
	}
	for (int col = 0; col < N; ++col) {
		for (int row = 0; row < M; ++row) {
			if (wall[col][row] == 0) {
				wall[col][row] = 1;
				makeWall(cnt + 1);
				wall[col][row] = 0;
			}
		}
	}

}

int main() {
	cin >> N >> M;
	for (int col = 0; col < N; ++col) {
		for (int row = 0; row < M; ++row) {
			cin >> lab[col][row];
			if (lab[col][row] == 1)wall[col][row] = 1;
			else if (lab[col][row] == 2)wall[col][row] = 2;
		}
	}
	makeWall(0);
	/*for (int col = 0; col < N; ++col) {
		for (int row = 0; row < M; ++row) {
			cout << lab[col][row] << " ";
		}
		cout << endl;
	}*/
	cout << result;
	return 0;
}
