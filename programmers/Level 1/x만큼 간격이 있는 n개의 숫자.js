function solution(x, n) {
    var answer = [];
    let startNumber=0;
    for(let j=0;j<n;++j){
        startNumber+=x;
        answer.push(startNumber);
    }
    return answer;
}
