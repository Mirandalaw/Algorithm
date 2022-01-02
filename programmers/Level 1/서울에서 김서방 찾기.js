function solution(seoul) {
    let answer ='김서방은';
    for(let i in seoul){
        if(seoul[i]==="Kim")answer+=` ${i}에 있다`;
    }
    return answer;
}
