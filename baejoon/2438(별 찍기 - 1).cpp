#include<iostream>
#include<math.h>
#define MAX 100+1
using namespace std;

int N;
int ans[MAX][MAX];

void init() {
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= N; ++j) {
			ans[i][j] = 1;
		}
	}
}

void Input() {
	cin >> N;
}

void Solution() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			ans[i][j] = 1;
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (ans[i][j] == 1)cout << "*";
		}
		cout << endl;
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
