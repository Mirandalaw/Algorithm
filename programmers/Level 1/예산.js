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
