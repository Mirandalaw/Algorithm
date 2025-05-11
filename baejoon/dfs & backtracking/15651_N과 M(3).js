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
    const [N,M] = input[0].toString().split(" ").map(Number);
    // console.log(solve(N,M,[]));
    solve(N,M);
    process.exit();
});

function solve(N,M){
    let answer = "";
    function backtracking(depth,picked){

        if(depth ===M) {
            answer+=picked.join(" ")+'\n';
            return;
        }

        for(let i = 1; i <=N; i++){
            backtracking(depth+1,[...picked, i]);
        }
    }
    backtracking(0,[]);
    console.log(answer.trim());
}