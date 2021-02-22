#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string N;
	cin >> N; //string형으로 받기
	int number1 = stoi(N),end=1;//stirng형 int형으로 변환
	vector<int> answer;
	int cnt = 0;
	while (end)
	{
		int sum = 0;
		for (int i = 0; i < 2; i++)
		{
			answer.push_back(number1 % 10); //6,2 -> 8,6 ->4,8 ->2,4
			number1 /= 10;
		}
		sum = answer[0] + answer[1];  // ->8  ->14 ->12 ->6
		if (sum >= 10)sum %= 10; //sum의 오른쪽 자리숫자
		answer.pop_back();//-> 2pop -> 6pop ->8pop ->4pop
		answer.push_back(sum);//8push ->  4push ->2push ->6push
		cnt++; //++++
		number1 = answer[0]*10 + answer[1];//->68 ->84->42 ->26
		answer.clear();
		if (to_string(number1) == N)
		{
			break; //종료시점
		}
	}
	cout << cnt;
	return 0;
}