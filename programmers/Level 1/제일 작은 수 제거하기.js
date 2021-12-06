function solution(arr) {
    // var answer = [];
    // if(arr.length==1){
    //     answer.push(-1);
    //     return answer;
    // }
    // const minValue=Math.min(...arr);
    // const idx = arr.indexOf(minValue);
    // arr.splice(idx,1)
    // return arr;
    
    if(arr.length==1){
        return [-1];
    }
    arr.splice(arr.indexOf(Math.min(...arr)),1);
    return arr
}
