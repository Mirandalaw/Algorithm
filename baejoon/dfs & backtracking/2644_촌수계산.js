const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on("line", function (line) {
    input.push(line);
}).on("close", function () {
    const N = Number(input[0]);
    const target = input[1].split(" ").map(Number);
    const M = Number(input[2]);
    const graph = Array.from({length: N + 1}, () => []);
    const visited = Array.from(N+1).fill(false);
    let answer = 0;
    for(let i = 3; i <=N;i++){
        const [u,v] = input[i].split(" ").map(Number);
        graph[u].push(v);
        graph[v].push(u);
    }
    function dfs(start,depth) {
        if(start ===target[1]){
            answer = depth;
            return;
        }
        visited[start] = true;
        for(const next of graph[start]){
            if(!visited[next]){
                dfs(next,depth+1);
            }
        }
    }
    dfs(target[0],0);

    console.log(answer);
})