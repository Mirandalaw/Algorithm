#include<iostream>
#include<vector>
#include<queue>
#define MAX 20001
using namespace std;

int N, M;
vector<int> barn[MAX];
int visited[MAX];

queue<int> q;

int maximum(int a, int b) {
	return a > b ? a : b;
}
int minmum(int a, int b) {
	return a < b ? a : b;
}

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int y, x;
		cin >> y >> x;
		barn[y].push_back(x);
		barn[x].push_back(y);
	}
	visited[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int barn_position = q.front();
		q.pop();
		for (int row = 0; row < barn[barn_position].size(); ++row) {
			int nx = barn[barn_position][row];
			if (!visited[nx]) {
				visited[nx] = visited[barn_position] + 1;
				q.push(nx);
			}
		}
	}
	int answer_barn_position = 55555;
	int max_distance = 0;
	int same_thing_cnt = 0;
	for (int col = 2; col <= N; ++col) {
		max_distance = maximum(visited[col], max_distance);
	}
	for (int col = 1; col <= N; ++col) {
		if (visited[col] == max_distance) {
			same_thing_cnt++;
			answer_barn_position = minmum(col, answer_barn_position);
		}
	}
	cout << answer_barn_position << " " << max_distance-1 << " " << same_thing_cnt;
}


int main() {
	solve();
	return 0;
}
