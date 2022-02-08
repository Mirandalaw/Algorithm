function aliquot(number){
    let answer=0;
    for(let i=1;i<=number;++i){
        if(number%i===0)answer++;
    }
    if(answer%2===0) return number;
    else return -number;
}
function solution(left, right) {
    var answer = 0;
    let number=0;
    for(let i=left;i<=right;++i){
        number = aliquot(i);
        answer+=number;
    }
    return answer;
}
