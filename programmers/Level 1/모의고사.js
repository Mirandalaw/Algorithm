function solution(answers) {
    
    let answer = [];
    const forgiveMathOne = [1,2,3,4,5,1,2,3,4,5]; //5
    const forgiveMathTwo = [2,1,2,3,2,4,2,5,2,1,2,3,2,4,2,5]; // 8 
    const forgiveMathThree = [3,3,1,1,2,2,4,4,5,5,3,3,1,1,2,2,4,4,5,5]; // 10
    
    let problem=answers.length;
    let score = new Array(3).fill(0);
    for(let i=0;i<problem;++i){
        if(answers[i]===forgiveMathOne[i%5])score[0]++;
        if(answers[i]===forgiveMathTwo[i%8])score[1]++;
        if(answers[i]===forgiveMathThree[i%10])score[2]++;
    }
    let maxScore = Math.max(...score);
    console.log(maxScore);
    console.log(score);
    for(let i=0;i<3;++i){
        if(maxScore==score[i])answer.push(i+1);
    }
    return answer;
}
