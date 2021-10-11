#include<iostream>
#include<algorithm>
#define MAX 100001
using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	int A[MAX];
	cin >> n;

	for (int tc = 0; tc < n; ++tc) {
		cin >> A[tc];
	}
	sort(A,A+n);
	cin >> m;
	for (int tc = 0; tc < m; ++tc) {
		int ab;
		cin >> ab;
		if (binary_search(A,A+n, ab)) {
			cout << "1"<<"\n";
		}
		else cout << "0"<< "\n";
	}
	return 0;

}
