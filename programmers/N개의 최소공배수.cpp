#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    long long lcm=1;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();++i){
        lcm*=arr[i];
    }
    int siz=arr.size();
    for(int start_num=arr[siz-1];start_num<=lcm;++start_num){
        bool istrue=true;
        int cnt=0;
        for(int i=0;i<siz;++i){
            if(start_num%arr[i]==0&&istrue==true){
                answer=start_num;
                cnt++;
            }
            else istrue=false;
        }
        if(cnt==siz)break;
    }
    return answer;
}
