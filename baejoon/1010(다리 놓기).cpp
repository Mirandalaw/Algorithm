#include<iostream>
#define MAX 31
using namespace std;

int T;
long long D[MAX][MAX];
void Input() {
	cin >> T;
}

void Solution() {
	for (int tc = 0; tc < T; ++tc) {

		long long answer = 0;
		int N, M;
		cin >> N >> M;
		for (int i = 1; i <= M; ++i) {
			D[1][i] = i;
		}
		for (int i = 2; i <= N; ++i) {
			for (int j = 2; j <=M; ++j) {
				D[i][j] = D[i][j - 1] + D[i - 1][j - 1];
			}
		}
		answer = D[N][M];
		cout << answer << "\n";
	}
}

void Solve() {
	Input();
	Solution();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	return 0;
}
