#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	string N;
	vector<int> answer;
	cin >> N;
	int solve = stoi(N);
	while (solve != 0)
	{
		answer.push_back(solve % 10);
		solve /= 10;
	}
	sort(answer.begin(), answer.end(), greater<int>());
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i];
	}
	return 0;
}