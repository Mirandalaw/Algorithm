const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let input = [];

rl.on("line", function (line) {
    input.push(line);
}).on("close", function () {
    // input 배열 처리

    const [N, M] = input[0].toString().split(' ').map(Number);
    const cards = input[1].toString().split(' ').map(Number);
    console.log(blackjack(cards,M));
    process.exit();
});

function blackjack(cards,M) {
    let maxSum = 0 ;
    let N = cards.length;

    function dfs(death, sum, start) {
        if(death === 3){
            if(sum<=M) maxSum=Math.max(sum,maxSum);
            return;
        }
        for(let i = start ; i < N; i++){
            dfs(death+1,sum+cards[i],i+1);
        }

    }
    dfs (0,0,0);
    return maxSum;
}
