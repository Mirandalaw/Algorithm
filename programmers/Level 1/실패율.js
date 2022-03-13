function solution(N, stages) {
    let answer= [];
    let total = stages.length;
    for(let i=1;i<=N+1;++i){
        //filter를 통해 i 스테이지에 실패한 사람의 수를 user에 저장
        let users = stages.filter(n=>n===i).length
        //[스테이지, 실패율] 을 answer에 할당
        answer.push([i, users/total]);
        //총 인원의 수를 실패한 사람의 수만큼 minus
        total-=users;
    }
    //for문의 루프를 N+1까지 해두었기 때문에 마지막 N+1 스테이지를 pop()
    answer.pop();
    //두번째 원소를 기준으로 내림차순 정렬
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
