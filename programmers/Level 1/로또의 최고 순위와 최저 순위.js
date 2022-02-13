function solution(lottos, win_nums) {
    var answer = [];
    let bestRanking=0;
    let worstRanking=0;
    let theNumberOfZero=0;
    let correctNumber=0;
    for(let i=0;i<lottos.length;++i){
        if(lottos[i]===0)theNumberOfZero++;
        else {
            for(let j=0;j<win_nums.length;++j){
                if(lottos[i]===win_nums[j]){
                    correctNumber++;
                }
            }
        }
    }
    bestRanking=7-(theNumberOfZero+correctNumber);
    worstRanking= 7-correctNumber;
    if(worstRanking>5)worstRanking=6;
    if(bestRanking>5)bestRanking=6;
    answer.push(bestRanking);
    answer.push(worstRanking);
    return answer;
}
