#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> stack(100);
	int tc;
	cin >> tc;
	for (int test_case = 0; test_case < tc; test_case++)
	{
		int number;
		cin >> number;
		if (number == 0)
		{
			stack.pop_back();
		}
		else stack.push_back(number);
	}
	int sum = 0;
	for (int i = 0; i < stack.size(); i++)
	{
		sum += stack[i];
	}
	cout << sum;
	return 0;
}