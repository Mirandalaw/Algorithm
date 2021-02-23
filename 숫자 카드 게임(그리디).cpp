/*숫자 카드 게임(그리디)*/

#include<iostream>
#include<algorithm>
#define MAX 100
using namespace std;

int main()
{
	int N, M;//행과 열
	int arr[MAX][MAX] = {0};
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	int min_num = 10000;
	int max_num = 0;
	for (int j = 0; j < M; j++)
	{
		for (int i = 0; i < N; i++)
		{
			min_num=min(min_num, arr[i][j]);
		}
		max_num = max(max_num, min_num);
	}
	cout << max_num;
	return 0;
}
