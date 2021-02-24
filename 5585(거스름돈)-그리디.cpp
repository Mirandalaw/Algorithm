#include<iostream>
using namespace std;

int main()
{
	int money;
	cin >> money;
	int change = 1000 - money;
	int result = 0;
	int store[6] = { 500,100,50,10,5,1 };//620
	for (int i = 0; i < 6; i++)
	{
		int count = 0;
		if (change - store[i] >= 0)
		{
			count += (change / store[i]);
			change -= (store[i] * count);
			result += count;
		}
	}
	cout << result;
	return 0;
}