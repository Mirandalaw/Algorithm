#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int main()
{
	int a, b, tc;
	cin >> tc;
	for (int test_case= 0; test_case < tc; test_case++)
	{
		int result,solve;

		vector<int>answer;
		cin >> a >> b;
		if (a % 10 == 0)
		{
			answer.push_back(10);
			cout <<  answer[0]<< endl;
		}
		else 
		{
			if (b >= 4)//b가 4보다 크다면
			{
				for (int j = 1; j <= 4; j++)
				{
					result = pow(a, j);
					answer.push_back(result % 10);//ex) a=3, b=7 (3 9 7 1) 4개가 반복
				}
				solve = b % 4;
				if (solve == 0) solve = 4;
				solve -= 1;
				cout << answer[solve] << endl;
			}
			else//b가 4보다 작을때 ->바로 계산해서 표현
			{
				result = pow(a, b);
				cout << (result % 10) << endl;
			}
		}
	}
	return 0;
}