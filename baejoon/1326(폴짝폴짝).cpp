#include<iostream>
#include<queue>
#define MAX 10000
using namespace std;

int N;
bool visited[MAX];
queue<pair<int, int>>q;
int a, b;
int arr[MAX];
int bfs(int currentPosition,int b) {
	q.push(make_pair(currentPosition, 0));
	visited[currentPosition] = true;
	while (!q.empty()) {
		int index = q.front().first;
		int value = arr[q.front().first];
		int cnt = q.front().second;
		q.pop();
		for (int i = 1; i <= MAX; ++i)
		{
			if (index == b) return cnt;
			if ((index + (value * i)) <= MAX&&!visited[index + (value * i)]) {
				q.push(make_pair(index + (value * i), cnt + 1));
				visited[index + (value * i)]=true;
			}
			if ((index - (value*i)) >= 1 && !visited[index - (value*i)]) {
				q.push(make_pair(index - (value*i), cnt + 1));
				visited[index - (value*i)] = true;
			}
		}
	}
	return -1;
}

int main() {
	cin >> N;
	
	int answer = 0;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
	cin >> a >> b;
	answer=bfs(a, b);
	cout << answer;
	return 0;
}
