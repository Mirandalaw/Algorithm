#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio;
	int tc,N;
	vector<int> number;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		scanf("%d", &N);
		number.push_back(N);
	}
	sort(number.begin(), number.end());
	
	for (int i = 0; i < tc; i++)
	{
		printf("%d\n", number[i]);
	}
	return 0;
}