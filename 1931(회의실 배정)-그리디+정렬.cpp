//다시 풀어보기 21.2.23

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct conf_of_time{
	int start;
	int end;
}C;

bool cmp(C s, C e)
{
	if (s.start == e.end)//종료시간이 동일, 그럼 시작시간이 빠른걸로
		return s.start < e.start;
	else
		return s.end < e.end;//종료시간이 동일 x,종료시간이 빠른순으로 정렬
}
int main()
{
	int N;// 회의의 수
	cin >> N;

	vector<C> confe(N);
	for (int i = 0; i < N; i++)
	{
		cin >> confe[i].start >> confe[i].end;
	}
	sort(confe.begin(), confe.end(), cmp);

	int cnt = 0; //회의 가능한 수
	int n = 0;//회의 종료지점 저장
	for (int i = 0; i < confe.size(); i++)
	{
		if (n <= confe[i].start)//회의 종료 지점이 다음 회의 시작지점보다 작으면
		{
			n = confe[i].end;//n에 다음 회의 종료 지점 저장
			cnt++;//회의 가능수 ++
		}
	}
	cout << cnt << endl;
	return 0;
}