#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

int main() {

	int N, M;
	int answer = 0;
	cin >> N >> M;
	set<string> a,ans;
	set<string>::iterator iter;
	for (int i = 0; i < N; ++i) {
		string c;
		cin >> c;
		a.insert(c);
	}
	for (int i = 0; i < M; ++i) {
		string c;
		cin >> c;
		iter = a.find(c);
		if (iter != a.end()) {
			ans.insert(*iter);
			answer++;
		}
	}
	
	cout << answer << endl;
	for (iter = ans.begin(); iter != ans.end();iter++) {
		cout << *iter<<endl;
	}
	return 0;
}
