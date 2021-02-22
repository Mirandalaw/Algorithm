//같은 반이 된 학생의 수만큼(다시풀어보기)
#include<iostream>
#define MAX 1001
int arr[MAX][6] = { 0 };
bool check[MAX][MAX] = { false };
using namespace std;
1 0 1 1 1
1 1 1

->solve1 -> 0 1 0 1
->solve2 -> 1 0 1 0
//int main()
//{
//	int student_Num;
//	S sd[MAX];
//	cin >> student_Num;
//	for (int y = 1; y <= student_Num; y++)
//	{
//		for (int x = 1; x <= 5; x++)
//		{
//			cin >> arr[y][x];
//		}
//	}
//	for (int x = 1; x <= 5; x++)
//	{
//		for (int y = 1; y <= student_Num-1; y++)
//		{
//			for (int z = y+1; z <= student_Num; z++)
//			{
//				if (arr[y][x] == arr[z][x]&&sd[y].check==false)
//				{
//					sd[y].cnt++;
//					sd[z].cnt++;
//					sd[y].student_number = y;
//					sd[z].student_number = z;
//					sd[y].check = true;
//					sd[z].check = true;
//				}
//			}
//		}
//	}
//	int max_cnt = 0;
//	int count = 0;
//	int max = 0;//같은 반이었던 사람이 가장 많은 학생을 임시 반장으로 출력하는 변수
//	int min = 0;//같은 반이었던 사람이 여러명인 경우 가장 작은 번호 출력하는 변수
//	for (int y = 1; y <= student_Num; y++)
//	{
//		if (max_cnt < sd[y].cnt)max_cnt = sd[y].cnt; //같은 반이었던 사람이 가장 많은 경우
//	}
//	for (int y = 1; y <= student_Num; y++)
//	{
//		if (max_cnt == sd[y].cnt) count++; //같은 반이었던 사람이 여러명인지 확인
//	}
//	if (count == 1) //한명일때
//	{
//		for (int i = 1; i <= student_Num; i++)
//		{
//			if (max_cnt==sd[i].cnt)max = sd[i].student_number;
//		}
//		cout << max;
//	}
//	if (count > 1)//여러명일때
//	{
//		for (int i = 1; i <= student_Num; i++)
//		{
//			if (min > sd[i].student_number)min = sd[i].student_number;
//		}
//		cout << min;
//	}
//	return 0;
//}
int main(void)
{
	int N;//학생수는 1000명
	cin >> N;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			cin >> arr[y][x];
		}
	}
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < N -1; y++)
		{
			for (int z = y + 1; z < N; z++)
			{
				if (arr[y][x] == arr[z][x])//4번 친구와 5번친구 둘다 서로 같은 반을 해봤다를 표현
				{
					check[y][z] = check[z][y] = true;
				}
			}
		}
	}
	int answer = -1;
	int prev_count = -1;
	for (int i = 0; i < N; i++)
	{
		int count = 0;
		for (int j = 0; j < N; j++)
		{
			if (check[i][j])count++;
		}
		if (count > prev_count) {
			answer = i + 1;
			prev_count = count;
		}
	}
	cout << answer << endl;
	return 0;	
}