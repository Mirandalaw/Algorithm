#include<iostream>
#define MAX 51
using namespace std;

typedef struct guitar_line {
	int package;
	int only_one;
}GL;

int main()
{
	int N, M;//100,50
	GL brend_price[MAX];
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> brend_price[i].package >> brend_price[i].only_one;
	}
	int min_package = 1001;
	int min_only_one = 1001;
	for (int i = 0; i < M; i++)//패키지의 가장 싼값.
	{
		if (min_package > brend_price[i].package)min_package = brend_price[i].package;
		if (min_only_one > brend_price[i].only_one)min_only_one = brend_price[i].only_one;
	}
	int answer = 0;
	//고려해야할 상황 -> 1. 끊어진 기타줄이 6개 이상일때, 2. 끊어진 기타줄이 6개 이하일때.
	if ((N / 6) > 0)//끊어진 기타줄이 6개 이상일 경우   
	{
		if (N % 6 == 0)//(1) N%6==0인경우
		{
			if (min_package <= (min_only_one * 6))answer = (min_package * (N / 6));
			else if (min_package > (min_only_one * 6)) answer = (min_only_one * 6) * (N / 6);
		}
		else//(2)N%6!=0인 경우
		{
			if (min_package < (min_only_one * 6))
			{
				if (min_package > (min_only_one * (N % 6)))	answer = (N / 6) * min_package + (min_only_one * (N % 6));
				else if (min_package <= (min_only_one * (N % 6)))answer = ((N / 6) * min_package) + min_package;//가장싼 패키지<낱개*필요한 기타줄
			}
			else answer = ((N / 6) * (min_only_one * 6)) + (min_only_one * (N % 6));
		}
	}
	else if ((N /6)== 0 )//6개 이하일때 최선의 선택은 가장싼 패키지의 값을 선택 > 가장 싼낱개의 가격*N을 비교
	{
		if ((min_only_one * N) < min_package) answer = min_only_one * N;
		else if ((min_only_one * N) > min_package)answer = min_package;
		else if ((min_only_one * N) == min_package) answer = min_package;
	}
	cout << answer;
	return 0;
}