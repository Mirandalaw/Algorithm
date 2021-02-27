#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	stack<int> st;
	int tc;
	string str;
	cin >> tc;

	for (int test_case = 0; test_case < tc; test_case)
	{
		cin >> str;
		if (str == "push")
		{
			int num;
			cin >> num;
			st.push(num);
		}
		else if (str == "pop")
		{
			if (st.empty())cout << -1<<endl;
			else
			{
				cout << st.top() << endl;
				st.pop();
			}
		}
		else if (str == "size")
		{
			cout << st.size() << endl;
		}
		else if (str == "empty")
		{
			cout << st.empty() << endl;
		}
		else if (str == "top")
		{
			if (st.empty()) cout << -1 << endl;
			else cout << st.top() << endl;
		}
	}
	return 0;
}