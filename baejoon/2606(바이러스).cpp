#include<iostream>
#include<vector>
#include<queue>
#define MAX 101
using namespace std;

int com;
int par;
int cnt = 0;
int arr[MAX][MAX];
int visited[MAX];
void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= com; ++i) {
			if (visited[i] == 0 && arr[x][i] == 1) {
				q.push(i);
				cnt++;
				visited[i] = 1;
			}
		}
	}
}

int main() {
	cin >> com;
	cin >> par;
	for (int i = 1; i <= par; ++i) {
		int y, x;
		cin >> x >> y;
		arr[y][x] = arr[x][y] = 1;
	}
	bfs(1);
	cout << cnt;
	return 0;
}
