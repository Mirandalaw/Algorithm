#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compared(pair<string,string> a,pair<string,string> b){
    if(a.second==b.second)return a.first<b.first;
    return a.second<b.second;
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<pair<string,string>>hash;
    for(int i=0;i<strings.size();++i){
        hash.push_back(make_pair(strings[i],strings[i].substr(n,1)));
    }
    sort(hash.begin(),hash.end(),compared);
    for(int i=0;i<hash.size();++i){
        answer.push_back(hash[i].first);
    }
    return answer;
}
