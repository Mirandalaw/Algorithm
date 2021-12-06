function solution(phone_number) {
    var answer='';
    let siz = phone_number.length;
    siz-=4;
    for(let i =0;i<siz;++i){
      answer+='*';
    }
    answer+=phone_number.substring(siz,phone_number.length);
    return answer;
}

//다른 사람의 풀이
function hide_numbers(s){
  var result = "*".repeat(s.length - 4) + s.slice(-4);
  //함수를 완성해주세요

  return result;
}
