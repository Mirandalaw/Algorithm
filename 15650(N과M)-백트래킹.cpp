#include<iostream>
#define MAX 9
using namespace std;
//전 문제와 다르게 for의 시작점을 바꾸어 버리며 앞의 값을 변화시키자
int N, M;
int arr[MAX];
void backtracking(int index,int current)//index 부분 넣어주고
{
	if (current == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << endl;
		return;
	}
	for (int i = index; i <= N; i++)
	{
		arr[current] = i; // arr[0] = 1; arr[1] = 2;
		backtracking(i+1,current + 1); //current=1,current=2;
	}
}
int main()
{
	cin >> N >> M; //4 2
	backtracking(1,0);
	return 0;
}