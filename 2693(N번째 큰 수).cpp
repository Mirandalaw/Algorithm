#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int test_case;
	int number;
	vector<int> solved;
	int answer = 0;
	cin >> test_case;
	for (int tc = 0; tc < test_case; tc++)
	{
		for (int i = 0; i < 10; i++)
		{
			cin >> number;
			solved.push_back(number);
		}
		sort(solved.begin(), solved.end(), greater<int>());
		cout << solved[2] << endl;
		solved.clear();
	}
	return 0;
}