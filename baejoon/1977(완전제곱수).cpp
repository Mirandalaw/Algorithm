#include<iostream>
#include<math.h>
#define MAX 100
using namespace std;

int main() {
	int M, N;
	cin >> M >> N;
	int n = 0;
	int min = 20000;
	int cnt = 0;
	for (int i = M; i <= N; ++i) {
		
		for (int j = 1; j <= MAX; ++j) {
			int a = pow(j, 2);
			
			if (a == i) {
				if (min > a)min = a;
				n += i;
				cnt++;
			}
		}
	}
	if (cnt == 0)cout << -1;
	else cout << n<<endl<<min;
	return 0;
}
