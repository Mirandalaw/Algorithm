function solution(n, m) {
    let answer =[];
    let gcb=0;
    for(let i=2;i<=n*m;++i){
        if(n%i===0&&m%i===0){
           gcb=i;
        }
    }
    if(gcb===0)gcb=1;
    answer.push(gcb);
    answer.push((n/gcb)*(m/gcb)*gcb);
    
    return answer;
}
