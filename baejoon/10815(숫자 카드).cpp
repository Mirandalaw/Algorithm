#include<iostream>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<ll>numberCard;
	for(int i=0;i<N;++i){
		ll num;
		cin >> num;
		numberCard.push_back(num);
	}
	sort(numberCard.begin(), numberCard.end());
	int M;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		ll num;
		cin >> num;
		if (binary_search(numberCard.begin(), numberCard.end(), num)) {
			cout << "1" << " ";
		}
		else cout << "0" << " ";
	}
	return 0;
}
