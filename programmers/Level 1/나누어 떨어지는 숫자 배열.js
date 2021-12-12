function solution(arr, divisor) {
    var answer = [];
    for (let value in arr){
        if(arr[value]%divisor===0) answer.push(arr[value]);
    }
    if(answer.length===0)return [-1];
    else answer.sort((a,b)=>{
        return a-b;
    })
    return answer;
}
