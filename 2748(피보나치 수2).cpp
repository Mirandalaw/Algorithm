#include<iostream>
#define MAX 90+1
using namespace std;

int N;
long long int arr[MAX];

void Input() {
	cin >> N;
}
void Solution() {

	if (N == 0)N = 0;
	if (N == 1)N = 1;
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= N; ++i) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	cout << arr[N];
}

void Solve() {
	Input();
	Solution();
}

int main() {
	ios::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();

	return 0;
}