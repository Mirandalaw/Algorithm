#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int start_num=0;
    while(start_num!=arr1.size()){
        int start_num2=0;
        vector<int> sum;
        while(start_num2!=arr2[0].size()){
            long long num=0;
            for(int i=0;i<arr2.size();++i){
                num+=arr1[start_num][i]*arr2[i][start_num2];
            }
            sum.push_back(num);
            start_num2++;
        }
        answer.push_back(sum);
        start_num++;
    }
    return answer;
}
