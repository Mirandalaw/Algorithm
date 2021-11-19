#include <string>
#include <vector>
#include <iostream>
#define MAX 101
using namespace std;

bool istrue(string a,string b){
    if(a.substr(a.size()-1,1)==b.substr(0,1))return true;
    else return false;
}
bool isSame(string a,string b){
    return a==b ? true:false;
}
int Min(int a,int b){
    return a<b ? a:b;
}
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<int> wrong_index;
    for(int i=0;i<words.size();++i){
        for(int j=i+1;j<words.size();++j){
            if(isSame(words[i],words[j])==true)wrong_index.push_back(j);
        }
    }
    for(int i=0;i<words.size()-1;++i){
        if(istrue(words[i],words[i+1])==false){
            wrong_index.push_back(i+1);
            i=words.size();
        }
    }
    int ans=101;
    if(wrong_index.size()==0){
        for(int i=0;i<2;++i){
            answer.push_back(0);
        }
    }
    else{
        for(int i=0;i<wrong_index.size();++i){
            ans=Min(ans,wrong_index[i]);
        }
        ans+=1;
        int Number=0;
        int peoNumber=ans%n;
        if(peoNumber==0){
            peoNumber=n;
            Number=ans/n;
        }
        else {
            Number=(ans/n)+1;
        }
        answer.push_back(peoNumber);
        answer.push_back(Number);
    }
    
    return answer;
}
