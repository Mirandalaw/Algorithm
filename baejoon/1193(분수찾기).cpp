#include<iostream>
#define MAX 10000
using namespace std;

int main() {
	int n;
	cin >> n;
	int sum = 0;
	int index = 0;
	//규칙성이 1+2+3+...n까지의 규칙성
	for (int i = 1; i < MAX; ++i) {
		sum += i;
		if (n <= sum) {
			index = i;
			break;
		}
	}
	sum -= n;
	if (index % 2 != 0) {//홀 수일 경우 올라감
		cout << 1 + sum << '/' << index - sum;
	}//짝수 일 경우 지그재그가 내려감
	else cout << index - sum << '/' << 1 + sum;
}
