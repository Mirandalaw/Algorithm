#include <string>
#include <vector>

using namespace std;
string change_base(int c,int number){
    string a;
    while(number !=0){
        int r = number%c;
        number/=c;
        if(r<10)a+=(to_string(r));
        else if(r>=10)a+=((char)(r-10)+'A');
    }
    string b;
    for(int i=a.size()-1;i>=0;--i){
        b+=a[i];
    }
    return b;
    
}
string solution(int n, int t, int m, int p) {
    string answer = "0";
    for(int i=1;i<=(t*m);++i){
        answer+=(change_base(n,i));
    }
    string a;
    int cnt=0;
    if(m==p)p=0;
    for(int i=0;i<answer.size();++i){
        if((i+1)%m==p&&(cnt!=t)){
            a+=answer[i];
            cnt++;
        }
    }
    return a;
}
