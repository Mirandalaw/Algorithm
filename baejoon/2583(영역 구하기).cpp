#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 101
using namespace std;
int N, M, K;
int paper[MAX][MAX];
int visited[MAX][MAX];
int answer = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
vector<int>cnt;
int number;
void dfs(int x, int y) {

	visited[y][x] = 1;
	number++;
	for (int dir = 0; dir < 4; ++dir) {
		int nx = dx[dir] + x;
		int ny = dy[dir] + y;
		if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
			if (!visited[ny][nx] && paper[ny][nx] == 0) {
				visited[ny][nx] = 1;
				paper[ny][nx] = paper[y][x] + 1;
				dfs(nx, ny);
			}
		}
	}
}
int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i) {
		int rec_startx, rec_starty, rec_endx, rec_endy;
		cin >> rec_startx >> rec_starty >> rec_endx >> rec_endy;// (0,2),(4,4)
		for (int col = rec_starty; col < rec_endy; ++col) {
			for (int row = rec_startx; row < rec_endx; ++row) {
				paper[col][row] = 1;
			}
		}
	}
	
	for (int col = 0; col < N; ++col) {
		for (int row = 0; row < M; ++row) {
			if (paper[col][row] == 0 && !visited[col][row]) {
				dfs(row, col);
				cnt.push_back(number);
				number = 0;
				answer++;
			}
		}
	}
	sort(cnt.begin(), cnt.end());
	cout << answer<<endl;
	for (int i = 0; i < cnt.size(); ++i) {
		cout << cnt[i] << " ";
	}
	return 0;
}
