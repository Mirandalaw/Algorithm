#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    vector<int> siz;
    for(int i=0;i<s.size();++i){
        if(s[i]==' ')siz.push_back(i);
    }
    siz.push_back(s.size());
    int n=0;
    for(int j=0;j<siz.size();++j){
        int cnt=0;
        for(int i=n;i<siz[j];++i){
            if(cnt==0&&s[i]>96&&s[i]<=122)s[i]-=32;//대문자로 
            else if(cnt!=0&&s[i]>64&&s[i]<=90)s[i]+=32;//소문자로
            cnt++;
        }
        n=siz[j]+1;
    }
    return s;
}
