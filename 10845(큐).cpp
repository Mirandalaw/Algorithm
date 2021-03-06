#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main()
{
	int order_number;
	queue<int> que;
	cin >> order_number;

	for(int i=0;i<order_number;i++)
	{
		string input_order;
		int number;
		cin >> input_order;
		if (input_order == "push")
		{
			cin >> number;
			que.push(number);
		}
		else if (input_order == "pop")
		{
			if (que.empty())cout << -1 << endl;
			else
			{
				cout << que.front() << endl;
				que.pop();
			}
		}
		else if (input_order == "size")cout << que.size() << endl;
		else if (input_order == "empty")
		{
			if (que.empty())cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (input_order == "front")
		{
			if (que.empty())cout << -1 << endl;
			else cout << que.front() << endl;
		}
		else if (input_order == "back")
		{
			if (que.empty())cout << -1<<endl;
			else cout << que.back()<<endl;
		}
	}
	return 0;
}