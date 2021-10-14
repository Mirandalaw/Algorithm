#include<iostream>
#include<queue>
#define MAX 100001
using namespace std;
bool visited[MAX];
int bfs(int N,int K){
	queue<pair<int, int>>q;
	q.push(make_pair(N, 0));
	visited[N] = true;

	while (!q.empty()) {
		int currentPosition = q.front().first;
		int time = q.front().second;
		q.pop();

		if (currentPosition == K)return time;
		if (currentPosition + 1 < MAX && !visited[currentPosition + 1]) {
			q.push(make_pair(currentPosition + 1, time + 1));
			visited[currentPosition + 1] = true;
		}
		if (currentPosition - 1 >= 0 && !visited[currentPosition - 1]) {
			q.push(make_pair(currentPosition - 1, time + 1));
			visited[currentPosition - 1] = true;
		}
		if (currentPosition * 2 < MAX && !visited[currentPosition * 2]) {
			q.push(make_pair(currentPosition * 2, time + 1));
			visited[currentPosition * 2] = true;
		}
	}
}
int main() {
	int N, K, answer = 0;
	cin >> N >> K;
	answer = bfs(N, K);
	cout << answer;
	return 0;
}
