#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	
	
	while (1)
	{
		string number;
		vector<int> Palin;
		bool answer = true;
		cin >> number;
		int num = stoi(number);
		if (num == 0)break;
		else
		{
			while (num != 0)
			{
				Palin.push_back(num % 10);// 1 2 3 1 -> 1 3 2 1
				num /= 10;
			}
			int j = Palin.size() - 1;
			for (int i = 0; i < Palin.size(); i++)
			{
				if (Palin[j] != Palin[i])
				{
					answer = false;
				}
				j--;
			}
			if (answer == true) cout << "yes"<<endl;
			else if (answer == false) cout << "no"<<endl;
		}
	}
	return 0;
}