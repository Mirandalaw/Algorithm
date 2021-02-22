#include<iostream>
#include<string>
#include<algorithm>
#define MAX 26
using namespace std;

int main()
{
	string str;
	int count[MAX] = { 0 };
	int target;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		str[i] = toupper(str[i]); //대문자로 만들기
	}
	sort(str.begin(), str.end()); //정리해서 순서대로 정렬
	for (int j=0; j < str.size(); j++)
	{
		count[str[j] - 'A']++;
	}
	int max = 0, cnt = 0; //최대값을 정해주기위해 max값 설정
	for (int i = 0; i < 26; i++)//최대값 정하기
	{
		if (max < count[i])
		{
			max = count[i];
			target = i;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (max == count[i])
		{
			cnt++;	
		}
	}
	if (cnt > 1)cout << "?";//나온 알파벳이 많다.
	else cout << char(target+'A');
	return 0;
}