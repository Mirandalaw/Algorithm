function solution(n) {
    var answer = [];
    let arr = n.toString();
    for(let i=arr.length-1;i>=0;--i){
        answer.push(parseInt(arr[i]));
    }
    return answer;
}
