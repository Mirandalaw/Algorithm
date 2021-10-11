#include<iostream>
#include<algorithm>
typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int K, N;
	ll answer=0;
	int arr[10001];
	cin >> K >> N;
	for (int i = 0; i < K; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + K);
	ll left = 1;
	ll right = arr[K-1];
	while (left <= right) {
		ll mid = (left + right) / 2;
		int sum = 0;
		for (int i = 0; i < K; ++i) {
			sum += (arr[i] / mid);
		}
		if (sum >= N) {
			left = mid + 1;
			answer = mid;
		}
		else if (sum < N) {
			right = mid - 1;
		}
	}
	cout << answer;
	return 0;
}
