#include <string>
#include <vector>
#define MAX 2001
using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long D[MAX];
    D[1]=1;
    D[2]=2;
    for(int i=3;i<=n;++i){
        D[i]=(D[i-2]+D[i-1])%1234567;
    }
    answer=D[n];
    return answer;
}
