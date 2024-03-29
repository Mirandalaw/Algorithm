#include<iostream>
#define MAX 9
using namespace std;
int N, M;
int arr[MAX];
int visited[MAX];
void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; ++i) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; ++i) {
		if (!visited[i]) {
			visited[i] = 1;
			arr[cnt] = i;
			dfs(cnt + 1);
			visited[i] = 0;
		}
	}
}
int main() {
	cin >> N >> M;
	dfs(0);
	return 0;
}
