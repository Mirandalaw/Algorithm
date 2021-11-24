//다른 사람의 풀이
function solution(absolutes,signs) {
  return absolutes.reduce((acc, val, i) => acc + (val * (signs[i] ? 1 : -1)), 0);
}
// 다른 사람의 풀이
function solution(absolutes, signs) {
    let answer = 0;
    absolutes.forEach((v, i) => {
        if (signs[i]) {
            answer += v;
        } else {
            answer -= v;
        }
    })
    return answer;
}

//나의 풀이 
function solution(absolutes, signs) {
    var answer=0;
    for (var i =0;i<signs.length;++i){
        if(signs[i]===true) answer+=absolutes[i];
        else answer-=absolutes[i];
    }
    return answer;
}
