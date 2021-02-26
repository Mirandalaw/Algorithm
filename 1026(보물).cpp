#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> arr;
	vector<int> mrr;
	
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end(),greater<int>());
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		mrr.push_back(num);
	}
	sort(mrr.begin(), mrr.end());
	

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		answer += (arr[i] * mrr[i]);
	}
	cout << answer;
	return 0;
}