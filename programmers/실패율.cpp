#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool compare(pair<int,float> a,pair<int,float> b){
    if(a.second==b.second)
        return a.first<b.first;
    return a.second>b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    unordered_map<int,float> un;
    float user=stages.size();
    for(int stage=1;stage<=N;++stage){
        float failure=0;
        for(int i=0;i<stages.size();++i){
            if(stage==stages[i])failure++;
        }
        if(user==0){
            if(stage<=N) un.insert(make_pair(stage,0));
        }
        else{
            float ave=(failure/user);
            un.insert(make_pair(stage,ave));
            user-=failure;
        }
    }
    vector<pair<int,float>> elms(un.begin(),un.end());
    sort(elms.begin(),elms.end(),compare);
    for(int i=0;i<elms.size();++i){
        answer.push_back(elms[i].first);
    }
    return answer;
}
