#include<iostream>

using namespace std;

int N, M;
int arr[9];
bool isthattrue[9];
void dfs(int current)
{
	if (current == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;//N=3, M=1
	}
	for (int i = 1; i <= N; i++)
	{
		if (!isthattrue[i])
		{
			isthattrue[i] = true;
			arr[current] = i;
			dfs(current + 1);
			isthattrue[i] = false;
		}
	}
}
int main()
{
	cin >> N >> M; //1~N±îÁö M°³
	dfs(0);
	return 0;
}