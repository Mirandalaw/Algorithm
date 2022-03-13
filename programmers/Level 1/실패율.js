function solution(N, stages) {
    let answer= [];
    let total = stages.length;
    for(let i=1;i<=N+1;++i){
        let users = stages.filter(n=>n===i).length
        answer.push([i, users/total]);
        total-=users;
    }
    answer.pop();
    answer= answer.sort((a,b)=>b[1]-a[1]);
    return answer.map(a=>a[0]);
}
/*
N = 5
2,1,2,6,2,4,3,3
stages   failure 
 1     : 1 / 8  0.125
 2     : 3 / 7  0.428  
 3     : 2 / 4  0.5
 4     : 1 / 2  0.5
 5     : 0 / 1  0
 => 3,4,2,1,5
 6 : 8 / 1
 N + 1 은 마지막 스테이지까지 클리어 한 사용자
 */
