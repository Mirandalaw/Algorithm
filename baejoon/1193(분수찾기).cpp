#include<iostream>
#define MAX 10000
using namespace std;

int main() {
	int n;
	cin >> n;
	int sum = 0;
	int index = 0;
	for (int i = 1; i < MAX; ++i) {
		sum += i;
		if (n <= sum) {
			index = i;
			break;
		}
	}
	sum -= n;
	if (index % 2 != 0) {
		cout << 1 + sum << '/' << index - sum;
	}
	else cout << index - sum << '/' << 1 + sum;
}
