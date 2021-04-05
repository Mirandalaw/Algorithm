#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> dp(12);
int topdown(int N)//재귀함수 
{
	if (N == 1)return 1;
	if (N == 2)return 2;
	if (N == 3)return 4;

	return topdown(N - 1) + topdown(N - 2) + topdown(N - 3);
}

int bottomup(int N)//메모제이션을 활용한 방법
{
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= N; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	return dp[N];
}

int main()
{
	int test_case;
	cin >> test_case;
	for (int tc = 0; tc < test_case; ++tc)
	{
		int N;
		cin >> N;
		
		cout << bottomup(N)<<endl;
	}
	return 0;
}