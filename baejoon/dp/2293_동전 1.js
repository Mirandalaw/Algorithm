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
    const [N, k] = input[0].split(' ').map(Number);
    const coins = input.slice(1, N + 1).map(Number);
    solve(k,coins);
    process.exit();
});

function solve(k,coins) {
    const dp = new Float64Array(k + 1);
    dp[0] = 1;
   for(const coin of coins) {
       for(let sum = coin; sum<=k;sum++){
           dp[sum] += dp[sum-coin];
       }
   }
   console.log(dp[k]);
}