function solution(s) {
    var answer='';
    let a=[];
    const arr =s.split(' ');
    answer+=(Math.min(...arr));
    answer+=(" "+Math.max(...arr));
    return answer;
}
