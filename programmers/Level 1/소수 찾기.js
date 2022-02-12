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
/*
n의 제곱근(루트 n)값으로 나우어 떨어지면 루트 n의 배수라는 뜻이므로 
소수가 아니게 됩니다.
ex) 25의 제곱근은 5입니다
5까지만 반복문이 돌아가더라도 25는 5의 배수이므로 i가 5일떄 나누어 
떨어지게 되고 소수가 아님을 판별할 수 있게 됩니다.
*/
