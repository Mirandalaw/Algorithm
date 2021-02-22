#include<iostream>

using namespace std;

int main()
{
	int X,stick=64,cnt=0;
	cin >> X;
	while (X != 0) //64 23
	{
		if (stick > X)stick /= 2;
		else
		{
			X -= stick;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}