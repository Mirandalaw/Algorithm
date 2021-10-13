#include<iostream>
#include<queue>
#include<algorithm>
#define MAX 26
using namespace std;

int N;
int direct_x[4] = { 0,1,0,-1 };
int direct_y[4] = { -1,0,1,0 };
int cnt = 0;
int map[MAX][MAX];
int visited[MAX][MAX];
int house[MAX*MAX];

void bfs(int start_x, int start_y) {
	queue<pair<int, int>> q;
	q.push(make_pair(start_x, start_y));
	visited[start_y][start_x] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		house[cnt]++;
		for (int dir = 0; dir < 4; ++dir) {
			int next_x = x + direct_x[dir];
			int next_y = y + direct_y[dir];
			if (next_x >= 0 && next_x < N&&next_y >= 0 && next_y < N&&visited[next_y][next_x] == 0 && map[next_y][next_x] != 0) {
				visited[next_y][next_x] = 1;
				q.push(make_pair(next_x, next_y));
			}
		}
	}
}

int main() {
	cin >> N;
	for (int col = 0; col < N; ++col) {
		for (int row = 0; row < N; ++row) {
			scanf_s("%1d", &map[col][row]);
			if (map[col][row] == 0)visited[col][row] = 1;
			else visited[col][row] = 0;
		}
	}
	for (int col = 0; col < N; ++col) {
		for (int row = 0; row < N; ++row) {
			if (visited[col][row] == 0) {
				bfs(row,col);
				cnt++;
			}
		}
	}
	
	cout << cnt<<endl;
	sort(house, house + cnt);
	for (int i = 0; i < cnt; ++i) {
		cout << house[i] << endl;
	}
	return 0;
}
