/* 큰 수의 법칙*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N, M, K;
	vector<int> arr;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		arr.push_back(number);
	}
	sort(arr.begin(), arr.end());
	int first = arr[N - 1];//가장 큰수
	int second = arr[N - 2];//두번째로 큰수

	int result = 0;

	while (1)
	{
		for (int i = 0; i < K; i++)
		{
			if (M == 0) break;
			result += first;
			M -= 1;
		}
		if (M == 0)break;
		result += second;
		M -= 1;
	}
	cout << result;
	return 0;
}