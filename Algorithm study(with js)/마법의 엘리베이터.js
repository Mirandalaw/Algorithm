function solution(storey) {
    var answer = 0;
    answer = makeResult(storey);
    return answer;
}

function makeResult(storey){
    let num = storey;
    let answer =0;
    while(num!=0){
        let tmp = num%10;
        if(tmp>5) {
            num+=(10-tmp);
            answer+=(10 - tmp);
        }
        else if(tmp == 5&&Math.floor(num/10)%10>=5) {
            num+=10-tmp
            answer+=10-tmp;
        }
        else {
            answer+=tmp;
        }
        num =Math.floor((num/10));
    }
    return answer;
}
