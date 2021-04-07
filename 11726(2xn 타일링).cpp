#include<iostream>
#define MAX 1001

using namespace std;
int dp[MAX] = { 0 };
int main()
{
	int n;//Å¸ÀÏ
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	cout << dp[n];
	return 0;	
}