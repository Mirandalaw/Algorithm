function solution(array, commands) {
    var answer = [];
    for(let i=0;i<commands.length;++i){
        var arr=[];
        for(let j=commands[i][0]-1;j<commands[i][1];++j){
            arr.push(array[j]);
        }
        arr.sort(function(a,b){
            return a-b;
        })
        answer.push(arr[commands[i][2]-1]);
    }
    return answer;
}

//다른사람의 풀이
function solution(array, commands) {
    let answer = [];
    for(let i = 0; i < commands.length; i++){
      let eachCommand = commands[i]
      let slice = array.slice(eachCommand[0] - 1, eachCommand[1])
      answer.push(slice.sort((a, b) => a - b)[eachCommand[2] - 1])
    }

    return answer;
}
