#include<iostream>
#define MAX 10000+1
using namespace std;

int D,K;
int a[MAX];
int b[MAX];

void Input() {
	cin >> D >> K;
}

void Solution() {
	a[1] = 1;
	b[1] = 0;
	a[2] = 0;
	b[2] = 1;
	for (int i = 3; i <= D; ++i) {
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2];
	}

	for (int i = 1; i <= K; ++i) {
		int answer = K - (a[D] * i);
		if (answer%b[D] == 0) {
			cout << i << "\n";
			cout<<(answer / b[D]);
			return;
		}

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
