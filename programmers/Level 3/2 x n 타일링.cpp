#include <string>
#include <vector>
#define MAX 60001
#define DIV 1000000007
using namespace std;

int solution(int n) {
    int answer = 0;
    int D[MAX];
    D[1]=1;
    D[2]=2;
    for(int i=3;i<=n;++i){
        D[i]=(D[i-2]+D[i-1])%DIV;
    }
    answer=D[n];
    return answer;
}
