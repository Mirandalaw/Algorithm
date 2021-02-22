#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

float main()
{
	int N, score;
	float sum=0;
	vector<float> solved;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> score;
		solved.push_back(score);
	}
	sort(solved.begin(), solved.end());
	for (int i = 0; i < N ; i++)
	{
		solved[i]= solved[i]/ solved[N-1] * 100;
		sum += solved[i];
	}
	printf("%.2f", sum / N);
	return 0;
}