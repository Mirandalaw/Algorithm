//나의 풀이
function solution(s) {
    var answer = '';
    var si = s.length;
    if(si%2===0){
        si/=2;
        answer=s[si-1]+s[si];
    }
    else {
        var num= Math.floor(si/=2);
        answer=s[num];
    }
    return answer;
}

function solution(s) {
    return s.length%2===0 ? s[Math.ceil(s.length/2)-1]+s[Math.ceil(s.length/2)] : s[Math.floor(s.length/2)];
}

/**다른 사람의 풀이*/
function solution(s) {
  return s.substr(Math.ceil(s.length/2)-1, s.length % 2 ===0 ? 2:1);
}
