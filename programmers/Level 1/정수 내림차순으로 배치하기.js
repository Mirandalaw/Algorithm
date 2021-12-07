function solution(n) {
    var answer = 0;
    var arr = [];
    while(n!=0){
        arr.push(n%10);
        n=Math.floor(n/10);
    }
    arr.sort(function(a,b){
        return b-a;
    })
    for(let i=arr.length-1,j=0;i>=0;--i){
        answer+=arr[i]*Math.pow(10,j);
        j++;
    }
    return answer;
}

//다른 사람의 풀이
function solution(n) {
    var answer = 0;
    var array = n.toString().split("");
    array.sort(function(a,b){ return b-a;});
    answer = parseInt(array.join(""));
    return answer;
}
