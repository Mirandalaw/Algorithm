#include <string>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	priority_queue<long long,vector<long long>,greater<long long>> pq;
    for(int i=0;i<scoville.size();++i){
        pq.push(scoville[i]);
    }
    int cnt=0;
    while(!pq.empty()){
        int tmp=0;
        queue<int> q; 
        for(int i=0;i<2;++i){
            q.push(pq.top());
            pq.pop();
        }
        int x=q.front();
        int y=q.back();
        tmp=x+(y*2);
        cnt++;
        pq.push(tmp);
        if(pq.top()>=K)return cnt;
        if(pq.size()==1&&pq.top()<=K)return -1;
    }
}
