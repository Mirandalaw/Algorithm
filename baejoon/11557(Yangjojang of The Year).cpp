#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


int main() {
	int N;
	cin >> N;
	unordered_map<string, int> u;
	for (int i = 0; i < N; ++i) {
		int S;
		cin >> S;
		int max = -1;
		for (int j = 0; j < S; ++j) {
			string sch;
			int num;
			cin >> sch>>num;
			if (num > max)max = num;
			u.insert(make_pair(sch, num));
		}
		for (auto i : u) {
			if (i.second == max) {
				cout << i.first << endl;
				break;
			}
		}
		
	}
}
