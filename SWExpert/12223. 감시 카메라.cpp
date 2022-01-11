#include<iostream>
#include<vector>
#define MAX 1001
using namespace std;
int map[MAX][MAX];
int answer = 0;
int biggestNumber(int a, int b) {// 최대값 찾는 함수
	return a > b ? a : b;
}
void init(int max) { // 초기화 시켜주는 함수
	for (int col = 1; col <= max; ++col) {
		for (int row = 1; row <= max; ++row) {
			map[col][row] = 0;
		}
	}
}

bool istrue(int theNumberOfCamera, vector<int>& picked, int region[MAX][4], int max) {// pick함수에서 고른 3개의 좌표값의 합이 3이 되는지 확인하는 함수
	/*for (int pickNumber = 0; pickNumber < picked.size(); ++pickNumber) {
		int selectCamera = picked[pickNumber];
		for (int col = region[selectCamera][1]; col <= region[selectCamera][3]; ++col) {
			for (int row = region[selectCamera][0]; row <= region[selectCamera][2]; ++row) {
				map[col][row]++;
			}
		}
	}*/
	for (int col = 1; col < max; ++col) {
		for (int row = 1; row < max; ++row) {
			if (map[col][row] == 3) return true;
		}
	}
}

void pick(int theNumberOfCamera, vector<int>& picked, int n, int region[MAX][4], int max) { //N개의 카메라 중 3개를 선택하는 함수
	if (n == 0) {
		/*	for (int i = 0; i < picked.size(); ++i) {
				cout << picked[i];
			}
			cout << endl;*/
		if (istrue(theNumberOfCamera, picked, region, max) == true)answer++;
		return;
	}
	/*for (int i = 1; i <= max; ++i) {
		for (int j = 1; j <= max; ++j) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int col = smallest; col < theNumberOfCamera; ++col) {
		picked.push_back(col);
		for (int y = region[col][1]; y <= region[col][3]; ++y) {
			for (int x = region[col][0]; x <= region[col][2]; ++x) {
				map[y][x]++;
			}
		}
		pick(theNumberOfCamera, picked, n - 1, region, max);
		for (int y = region[picked.back()][1]; y <= region[picked.back()][3]; ++y) {
			for (int x = region[picked.back()][0]; x <= region[picked.back()][2]; ++x) {
				map[y][x]--;
			}
		}
		picked.pop_back();
	}
}

int main() {
	int test_case;
	cin >> test_case;
	for (int tc = 0; tc < test_case; ++tc) {
		int theNumberOfCamer;
		cin >> theNumberOfCamer;
		int region[MAX][4];
		int max = 0;
		for (int col = 0; col < theNumberOfCamer; ++col) {
			for (int row = 0; row < 4; ++row) {
				cin >> region[col][row];
				max = biggestNumber(max, region[col][row]);
			}
		}
		vector<int> a;
		pick(theNumberOfCamer, a, 3, region, max);
		cout << "#" << tc + 1 << " " << answer << endl;
		answer = 0;
		init(max);
	}
	return 0;
}
