#include<iostream>
#include<string>
#define MAX 83
using namespace std;

int main()
{
	string binary1, binary2;
	int solve1[MAX] = { 0 };
	int solve2[MAX] = { 0 };
	int answer[MAX] = { 0 };
	cin >> binary1 >> binary2; //1010 101
	if (binary1.size() > binary2.size())
	{
		int j = 0;
		for (int i = binary1.size()-1; i >=0; i--)
		{
			solve1[j] = stoi(binary1.substr(i, 1));//0 1 0 1
			j++;
		}
		int binary2_index = binary1.size() - binary2.size();
		int k = 0;
		for (int i = binary1.size() - 1 - binary2_index; i >= 0; i--)
		{
			solve2[k] = stoi(binary2.substr(i, 1));
			k++;
		}
		for (int x =0; x <binary1.size(); x++)
		{
			answer[x] = solve1[x] + solve2[x];
		}
		for (int x = 0; x < binary1.size(); x++)
		{
			if (answer[x] == 2)
			{
				answer[x] = 0;
				answer[x + 1] = answer[x + 1] + 1;
			}
			else if (answer[x] == 3)
			{
				answer[x] = 1;
				answer[x + 1] = answer[x + 1] + 1;
			}
		}
		int b1 = binary1.size();
		if (answer[b1] == 0)b1--;
		for (int i = b1; i>=0; i--)
		{
			cout << answer[i];
		}
	}
	else if (binary1.size() < binary2.size())
	{
		int j = 0;
		for (int i = binary2.size() - 1; i >= 0; i--)
		{
			solve1[j] = stoi(binary1.substr(i, 1));//0 1 0 1
			j++;
		}
		int binary1_index = binary2.size() - binary1.size();
		int k = 0;
		for (int i = binary2.size() - 1 - binary1_index; i >= 0; i--)
		{
			solve2[k] = stoi(binary2.substr(i, 1));
			k++;
		}
		for (int x = 0; x < binary2.size(); x++)
		{
			answer[x] = solve1[x] + solve2[x];
		}
		for (int x = 0; x < binary2.size(); x++)
		{
			if (answer[x] == 2)
			{
				answer[x] = 0;
				answer[x + 1] = answer[x + 1] + 1;
			}
			else if (answer[x] == 3)
			{
				answer[x] = 1;
				answer[x + 1] = answer[x + 1] + 1;
			}
		}
		int b2 = binary2.size();
		if (answer[b2] == 0)b2--;
		for (int i = b2; i >= 0; i--)
		{
			cout << answer[i];
		}
	}
	else if (binary1.size() == binary2.size())
	{
		int j = 0;
		for (int i = binary2.size() - 1; i >= 0; i--)
		{
			solve1[j] = stoi(binary1.substr(i, 1));//0 1 0 1
			j++;
		}
		int k = 0;
		for (int i = binary2.size() - 1 ; i >= 0; i--)
		{
			solve2[k] = stoi(binary2.substr(i, 1));
			k++;
		}
		for (int x = 0; x < binary2.size(); x++)
		{
			answer[x] = solve1[x] + solve2[x];
		}
		for (int x = 0; x < binary2.size(); x++)
		{
			if (answer[x] == 2)
			{
				answer[x] = 0;
				answer[x + 1] = answer[x + 1] + 1;
			}
			else if (answer[x] == 3)
			{
				answer[x] = 1;
				answer[x + 1] = answer[x + 1] + 1;
			}
		}
		int b2 = binary2.size();
		if (answer[b2] == 0)b2--;
		for (int i = b2; i >= 0; i--)
		{
			cout << answer[i];
		}
	}
	return 0;
}