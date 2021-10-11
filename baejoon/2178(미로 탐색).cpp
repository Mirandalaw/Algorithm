#include<iostream>
#include<queue>
#define MAX 101
using namespace std;

int direct_x[4] = { 0,1,0,-1 };
int direct_y[4] = { -1,0,1,0 };
int N, M;
int map[MAX][MAX];
int visited[MAX][MAX];
int answer = 0;
void bfs(int start_x,int start_y) {
	queue<pair<int,int>> q;
	q.push(make_pair(start_x,start_x));
	visited[start_y][start_x] ++;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int dir = 0; dir < 4; ++dir) {
			int next_x = x + direct_x[dir];
			int next_y = y + direct_y[dir];
			if (next_y>=0&&next_y<N&&next_x>=0&&next_x<M&&visited[next_y][next_x] == 0&&map[next_y][next_x]==1) {
				visited[next_y][next_x] = visited[y][x] + 1;
				q.push(make_pair(next_x, next_y));
			}
		}

	}
}


int main() {
	cin >> N >> M;
	for (int col = 0; col < N; ++col) {
		for (int row = 0; row < M; ++row) {
			scanf("%1d", &map[col][row]);
		}
	}
	
	bfs(0, 0);
	
	cout << visited[N-1][M-1];
	return 0;
}
