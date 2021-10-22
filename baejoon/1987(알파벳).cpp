#include<iostream>
#include<queue>
#define MAX 21
using namespace std;

char alp[MAX][MAX];
int R, C;
int answer;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
bool visited[26];
//void bfs(int start_x, int start_y) {
//	answer = 0;
//	queue<pair<int, int>>q;
//	q.push(make_pair(start_x, start_y));
//	visited[alp[start_y][start_x] - 'A'] = true;
//	while (!q.empty()) {
//		int x = q.front().first;
//		int y = q.front().second;
//		q.pop();
//		for (int dir = 0; dir < 4; ++dir) {
//			int nx = x + dx[dir];
//			int ny = y + dy[dir];
//			if (nx >= 0 && nx < C&&ny >= 0 && ny < R) {
//				if (!visited[alp[ny][nx] - 'A']) {
//					if (alp[ny][nx] != alp[y][x]) {
//						q.push(make_pair(ny, nx));
//						visited[alp[ny][nx]-'A'] = true;
//						answer++;
//					}
//				}
//			}
//		}
//	}
//}
void dfs(int start_x, int start_y, int result) {
	if (answer < result)answer = result;
	for (int dir = 0; dir < 4; ++dir) {
		int nx = start_x + dx[dir];
		int ny = start_y + dy[dir];
		if (nx >= 0 && nx < C&&ny >= 0 && ny < R) {
			if (!visited[alp[ny][nx] - 'A']) {
				visited[alp[ny][nx] - 'A'] = true;
				dfs(nx, ny, result + 1);
				visited[alp[ny][nx] - 'A'] = false;
			}
		}
	}
}

int main() {/*
	int result = -1;*/
	cin >> R >> C;
	for (int col = 0; col < R; ++col) {
		for (int row = 0; row < C; ++row) {
			cin >> alp[col][row];
		}
	}
	visited[alp[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << answer;
	/*for (int col = 0; col < R; ++col) {
		for (int row = 0; row < C; ++row) {
			bfs(row, col);
			if (result < answer)result = answer;
			for (int i = 0; i < 26; ++i) {
				visited[i] = false;
			}
		}
	}*/
	return 0;
}
