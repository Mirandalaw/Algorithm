#include<iostream>
#define MAX 9
using namespace std;
int N, M;
int arr[MAX];
int visited[MAX];
void dfs(int cnt,int current) {
	if (cnt == M) {
		for (int i = 0; i < M; ++i) {
			cout << arr[i]<<" ";
		}
		cout << "\n";
		return;
	}
	for (int i = current; i <= N; ++i) {
		arr[cnt] = i;
		dfs(cnt + 1,i);
	}
}
int main() {
	cin >> N >> M;
	dfs(0,1);
	return 0;
}
