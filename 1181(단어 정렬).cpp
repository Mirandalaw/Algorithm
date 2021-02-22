#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int main()
{
	int N;
	vector < pair<int, string>> answer;
	char alpa[51];
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> alpa;
		answer.push_back({ strlen(alpa),alpa });
	}
	stable_sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());//중복제거
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i].second << endl;
	}
	return 0;
}