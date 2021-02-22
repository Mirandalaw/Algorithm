#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	int cnt = 0;
	for (int i = 0; i < tc; i++)
	{
		bool answer = true;
		vector<string> solve;
		string N;
		cin >> N;
		if (N.size() == 1)cnt++;
		else
		{
			for (int i = 0; i < N.size(); i++)
			{
				if (N[i] != N[i + 1] || i + 1 >= N.size())
				{
					solve.push_back(N.substr(i, 1));
				}
			}
			sort(solve.begin(), solve.end());
			for (int i = 0; i < solve.size()-1; i++)
			{
				if (solve[i] == solve[i + 1] ||i+1>=solve.size()) answer = false;
			}

			if (answer == true)cnt++;
		}
	}
	cout << cnt;
	return 0;
}