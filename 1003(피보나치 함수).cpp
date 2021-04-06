#include<iostream>
#include<vector>
#define MAX 41
typedef struct pi{
	int index,num_of_zero, num_of_one;
}p;
using namespace std;

vector<p> dp(MAX);
p bottomup(int N)
{
	dp[0].index = 0;
	dp[0].num_of_zero = 1;
	dp[1].index = 1;
	dp[1].num_of_one = 1;
	for (int i = 2; i <= N; ++i)
	{
		dp[i].index = dp[i - 1].index + dp[i - 2].index;
		dp[i].num_of_zero = dp[i - 1].num_of_zero + dp[i - 2].num_of_zero;
		dp[i].num_of_one = dp[i - 1].num_of_one + dp[i - 2].num_of_one;
	}
	return dp[N];
}

int main()
{
	int test_case;
	cin >> test_case;
	for (int tc = 0; tc < test_case; ++tc)
	{
		int N ;

		cin >> N;
		cout<<bottomup(N).num_of_zero<<" "<<bottomup(N).num_of_one<<endl;
	}
	return 0;
}