#include<iostream>
#include<queue>
#define MAX 1001
using namespace std;

int arr[MAX][MAX];
int visited[MAX];
int N, M, answer = 0;
void bfs(int start) {
	queue<int>q;
	q.push(start);
	visited[start] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= N; ++i) {
			if (visited[i] == 0 && arr[x][i] == 1) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int num = 0; num < M; ++num) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = arr[y][x] = 1;
	}
	for (int col = 1; col <= N; ++col) {
		for (int row = 1; row <= N; ++row) {
			if (visited[col] == 0) {
				bfs(col);
				answer++;
			}
				//cout << arr[col][row];
		}
		//cout << endl;
	}
	cout << answer;
	return 0;
}
