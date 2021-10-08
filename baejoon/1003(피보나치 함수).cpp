#include<iostream>
using namespace std;

typedef struct a {
	int zero_count=0;
	int one_count=0;
}a;

int main() {
	int tc = 0;
	a arr[41];
	cin >> tc;
	for (int test_case = 0; test_case < tc; ++test_case) {
		int num = 0;
		cin >> num;
		arr[0].zero_count = 1;
		arr[0].one_count = 0;
		arr[1].zero_count = 0;
		arr[1].one_count = 1;
		for (int i = 2; i <= num; ++i) {
			arr[i].zero_count = arr[i - 1].zero_count + arr[i - 2].zero_count;
			arr[i].one_count = arr[i - 1].one_count + arr[i - 2].one_count;
		}
		cout << arr[num].zero_count << " " << arr[num].one_count<<endl;
	}
	return 0;
}
