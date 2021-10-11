#include<iostream>
#include<algorithm>
#define MAX 1000001
using namespace std;

int main() {
	int tc;
	int num1 = 1;
	int num0 = 0;
	scanf("%d", &tc);
	for (int test_case = 0; test_case < tc; ++test_case) {
		int N, M;
		scanf("%d", &N);
		int arr[MAX];
		for (int i = 0; i < N; ++i) {
			scanf("%d", &arr[i]);
		}
		sort(arr, arr + N);
		scanf("%d", &M);
		for (int i = 0; i < M; ++i) {
			int num;
			scanf("%d", &num);

			if (binary_search(arr, arr + N, num)) {
				printf("%d\n", num1);
			}
			else printf("%d\n", num0);
		}
	}
	return 0;
}
