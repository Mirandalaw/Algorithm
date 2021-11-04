#include <string>
#include <vector>
#define MAX 30
using namespace std;
int kind[MAX];
int visited[MAX];
int solution(vector<vector<string>> clothes) {
    int answer = 0;
    int cnt=0;
    for(int col=0;col<clothes.size();++col){
        visited[col]=1;
        for(int i=col+1;i<clothes.size();++i){
            if(clothes[col][1]==clothes[i][1]&&!visited[i]){
                kind[cnt]++;
                visited[i]=1;
            }
        }
        if(!visited[col+1])cnt++;
    }
    int ans=1;
    for(int i=0;i<cnt;++i){
        ans*=(kind[i]+2);
    }
    ans--;
    answer=ans;
    return answer;
}
