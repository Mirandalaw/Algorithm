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
    const A = input[1].split(' ').map(Number);
    solve(A,N);
    process.exit();
});

function solve(arr,N) {
    const dp = Array(N).fill(1);
    for(let i = 1; i< N; i++){
        for(let j = 0 ; j< i; j++){
            if(arr[j]>arr[i]){
                dp[i]= Math.max(dp[i],dp[j]+1);
            }
        }
    }
    console.log(Math.max(...dp));
}