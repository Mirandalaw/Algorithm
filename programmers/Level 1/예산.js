function solution(d, budget) {
    var answer = 0;
    d.sort(function(a,b){
        if(a>b)return 1;
        if(a===b)return 0;
        if(a<b)return -1;
    });
    var index=0;
    while(true){
        if(budget-d[index]>=0){
            budget-=d[index];
            answer+=1;
            index+=1;
        }
        else return answer;
    }
} 

function solution(d, budget) {
    d.sort((a,b)=>{return a-b});
    let result=0;
    let cnt=0;
    for (let i=0;i<d.length;++i){
        result+=d[i];
        if(result<=budget){
            cnt++;
        }
    }
    return cnt;
}

//다른 사람의 풀이
function solution(d, budget) {
    d.sort((a, b) => a - b);

    while (d.reduce((a, b) => (a + b), 0) > budget) d.pop();

    return d.length;
}
