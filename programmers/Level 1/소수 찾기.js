function primeNumber(n){
    for(let i =2;i<=Math.sqrt(n);++i){
        if(n%i===0)return true;
    }
    return false;
}

function solution(n) {
    var answer = 0;
    if(n>=2)answer+=1;
    for(let i=3;i<=n;++i){
        if(primeNumber(i)===false)answer++;
    }
    return answer;
}
