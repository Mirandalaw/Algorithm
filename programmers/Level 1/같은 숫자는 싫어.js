function solution(arr)
{
    var answer = [];
    let target = arr[0];
    answer.push(target);
    for(let i=0;i<arr.length;++i){
        if(target!==arr[i]){
            answer.push(arr[i]);
            target=arr[i];
        }
    }
    
    return answer;
}
