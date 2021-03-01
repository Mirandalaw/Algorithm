#include<iostream>
#include<vector>
using namespace std;
/*
라디오에 버튼이있다.
1. 첫 번째 버튼은 주파수를 1MHz 증가시킨다.
2. 두 번째 버튼은 주파수를 1MHz 감소시킨다.
3. 나머지 N개의 버튼은 즐겨찾기 기능으로, 미리 지정된 주파수로 이동*/

int main()
{
	int A, B;
	int N, store_minus = 0, solve = 0;
	vector<int>third_list;
	int minus[5] = { 0 };
	
	cin >> A >> B;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int favorite_button;
		cin >> favorite_button;
		third_list.push_back(favorite_button);
	}
	int answer = 0;
	store_minus = abs(A - B);//A와 B의 차
	for (int i = 0; i < N; i++)
	{
		minus[i] =abs( B- third_list[i]);//B의 주파수와 즐겨찾기 목록 주파수의 차 1,2,3
	}
	int min = 999;
	for (int i = 0; i < N; i++)
	{
		if (min > minus[i])
		{
			min = minus[i];
			solve = i;
		}
	}
	if (store_minus <=min+1) answer = store_minus;
	else
	{
		answer = abs(minus[solve]) + 1;
	}
	cout << answer;
	return 0;
}