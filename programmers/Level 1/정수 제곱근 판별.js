function solution(n) {
    let answer = 0;
    if(isNaN(Math.sqrt(n))||!Number.isInteger(Math.sqrt(n))){
        return -1;
    }
    else {
        answer=Math.sqrt(n)+1;
        answer=Math.pow(answer,2);
        
    }
    return answer;
}
