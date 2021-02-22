#include<iostream>
#include<vector>
#define MAX 101
using namespace std;

int main()
{
	bool visited_arr[MAX] = { 0 };
	int N,cnt=0;
	int push_number;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> push_number;
		visited_arr[push_number] = 1;
		
	}
	for (int i = 1; i <= 100; i++)
	{
		if (visited_arr[i] == 1)cnt++;
	}
	cout << N - cnt;
	return 0;
}