#include<iostream>
#include<vector>

using namespace std;

int YungSik(int N)//30초마다 10원씩 청구
{
	int cnt=0;
	cnt = N / 30;
	N /= 30;
	if (N < 30)
	{
		cnt++;
	}
	return cnt;
}

int MinSik(int N)//60초마다 15원씩 청구
{
	int cnt = 0;
	cnt = N / 60;
	N /= 60;
	if (N < 60)
	{
		cnt++;
	}
	return cnt;
}

int main()
{
	int test_case;//저번달에 통화의 개수
	int N;//저번달에 통화한 시간
	int M=0, Y=0;
	cin >> test_case;
	for (int tc = 0; tc < test_case; tc++)
	{
		cin >> N;
		Y += 10 * YungSik(N);
		M += 15 * MinSik(N);
	}
	if (Y > M)cout << "M" << " " << M << endl;
	else if (M > Y)cout << "Y" << " " << Y << endl;
	else if (M == Y)cout << "Y"<<" " <<"M" << " " <<Y<< endl;
	
	return 0;
}