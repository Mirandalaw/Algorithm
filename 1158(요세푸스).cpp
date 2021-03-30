#include<iostream>
#include<queue>
#define MAX 5000+1
using namespace std;

int main()
{
	int N, K;
	int tb[MAX];
	scanf_s("%d%d", &N, &K);
	queue<int> table;
	for (int col = 1; col <= N; ++col)
	{
		tb[col] = col;
	}
	int c = 1;
	while (table.size() != N)
	{
		for (int col = 1; col <= N; ++col)
		{
			if (c % K == 0 && tb[col] != 0) {
				table.push(tb[col]);
				tb[col] = 0;
				c++;
			}
			else if (tb[col] != 0) c++;
		}
	}
	printf("<");
	int count = 1;
	while (!table.empty())
	{
		count++;
		if (count == N+1) cout << table.front() ;
		else cout << table.front() << ", ";
		table.pop();
	}
	printf(">");
	return 0;
}