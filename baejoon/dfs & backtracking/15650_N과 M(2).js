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
    const visited = Array.from({length : N}).fill(false);
    function backtracking(depth,picked,start) {
        if(depth === M) {
            console.log(picked.join(" "));
            return;
        }
        for(let i = start; i <=N;i++){
            if(!visited[i]){
                visited[i] = true;
                backtracking(depth+1,[...picked,i],i+1);
                visited[i] = false;
            }
        }
    }
    backtracking(0,[],1);
}