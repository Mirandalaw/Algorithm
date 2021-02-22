/* 큰 수의 법칙
N(2<=N<=1000),M(1<=M<=10000),K(1<=K<=10000) 의 자연 수가 주어지며, 각 자 연수는 공백으로 구분
N은 정수의 개수, M은 M번 더하기, K는 배열의 특정한 인덱스(번호)에 해당하는 수가 연속해서 K번을 초과하여 더해질 수 없음.

ex)  2,4,5,4,6 M=8,K=3 
6+6+6+5+6+6+6+5 =46

*/
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
