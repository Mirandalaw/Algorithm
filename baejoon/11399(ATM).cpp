#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> peo;
	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;
		peo.push_back(num);
	}
	sort(peo.begin(), peo.end());
	int answer = 0;
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		sum = 0;
		for (int j = 0; j <= i; ++j) {
			sum += peo[j];
		}
		answer += sum;
	}
	cout << answer;
	return 0;
}
