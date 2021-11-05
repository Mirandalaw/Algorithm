#include <string>
#include <vector>
#include<queue>
#define MAX 100
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int v[MAX];
    for(int row=0;row<progresses.size();++row){
        int success=(MAX-progresses[row]);
        if(success%speeds[row]==0)v[row]=(success/speeds[row]);
        else v[row]=((success/speeds[row])+1);
    }
    // for(int row=0;row<progresses.size();++row){
    //     answer.push_back(v[row]);
    // }
    int value= v[0];
    int cnt=1;
    for(int i=0;i<(progresses.size()-1);++i){
        if(value<v[i+1]){
            answer.push_back(cnt);
            cnt=1;
            value=v[i+1];
        }
        else if(value>=v[i+1]){
            cnt++;
        }
    }
    answer.push_back(cnt);
    return answer;
}
