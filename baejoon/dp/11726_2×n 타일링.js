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
    const N =Number(input[0]);
    solve(N);
    process.exit();
});

function solve(n) {
    const mod = 10007;
    const dp = [];
    dp[0] = 0;
    dp[1] = 1;
    for(let i =2 ; i<=n+1;i++ ){
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }
    console.log(dp[n+1]);
}