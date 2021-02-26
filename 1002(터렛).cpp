#include<iostream>
#include<math.h>
using namespace std;

typedef struct Tur {
	int x, y ,r;
}T;

int main()
{
	int tc;
	cin >> tc;
	for (int test_case = 0; test_case < tc; test_case++)
	{
		T worker[2];
		for (int i = 0; i < 2; i++)
		{
			cin >> worker[i].x >> worker[i].y >> worker[i].r;
		}
		int big_r=0, small_r=0;
		double d2 = pow(worker[0].x - worker[1].x, 2.0) + pow(worker[0].y - worker[1].y, 2.0);//각 원의 정점과의 거리
		double d = sqrt(d2);
		if (worker[0].r < worker[1].r)
		{
			big_r = worker[1].r;
			small_r = worker[0].r;
		}
		else
		{
			big_r = worker[0].r;
			small_r = worker[1].r;
		}
		if (worker[0].x == worker[1].x && worker[0].y == worker[1].y && worker[0].r == worker[1].r)cout << -1 << endl;
		else if (big_r<d+small_r&&big_r>d-small_r) cout << 2 << endl;
		else if (big_r==d + small_r || big_r==d - small_r)cout << 1 << endl;
		else if (big_r>d + small_r || big_r<d - small_r)cout << 0 << endl;
	}
	return 0;
}