#include<iostream>
#include<algorithm>
#define MAX 151
using namespace std;

int main()
{
	int score[8], sum = 0;
	int participant[MAX] = { 0 };
	int idx[5];
	for (int i = 0; i < 8; i++)
	{
		cin >> score[i];
		participant[score[i]] = i + 1;
	}
	sort(score, score + 8, greater<int>());

	for (int i = 0; i < 5; i++)
	{
		sum += score[i];
	}
	cout << sum << endl;
	for (int i = 0; i < 5; i++)
	{
		idx[i] = participant[score[i]];
	}
	sort(idx, idx + 5);
	for (int i = 0; i < 5; i++)
	{
		cout << idx[i] << " ";
	}
	return 0;
}