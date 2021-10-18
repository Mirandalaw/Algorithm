#include<iostream>
#include<string>
#include<regex>

using namespace std;

int main() {
	int tc;
	cin >> tc;
	for (int test_case = 0; test_case < tc; ++test_case) {
		string bits;
		cin >> bits;
		regex pattern("(100+1+|01)+");
		if (regex_match(bits, pattern)) {
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
	return 0;
}
