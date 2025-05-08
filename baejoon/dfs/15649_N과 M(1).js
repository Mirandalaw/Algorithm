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
    const visited = Array(N + 1).fill(false);
    function dfs(start,picked){
        if(M===picked.length){
            console.log(picked.join(" "));
            return;
        }
        for(let i = 1; i<=N;i++){
            if(!visited[i]){
                visited[i] =true;
                dfs(i+1,[...picked,i]);
                visited[i]= false;
            }
        }
    }
    dfs(1, []);
}