#include <string>
#include <vector>
#define MAX 100000+1
using namespace std;

int solution(int n) {
    int answer = 0;
    int D[MAX];
    D[0]=0;
    D[1]=1;
    for(int i=2;i<=n;++i){
        D[i]=(D[i-2]+D[i-1])%1234567;
    }
    answer=D[n];
    return answer;
}
