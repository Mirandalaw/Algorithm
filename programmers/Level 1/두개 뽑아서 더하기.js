function solution(numbers) {
    let answer= [];
    let set = new Set();
    for(let i=0;i<numbers.length;++i){
        for(let j=i+1;j<numbers.length;++j){
            answer.push(numbers[i]+numbers[j]);
        }
    }
    
    set.add(answer);
    console.log(set);
    return answer;
}
