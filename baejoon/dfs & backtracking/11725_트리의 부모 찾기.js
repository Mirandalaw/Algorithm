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
    const graph = Array.from({ length: N + 1 }, () => []);
    const parents = Array(N + 1).fill(0);

    for (let i = 1; i < N ; i++) {
        const [u,v] = input[i].split(" ").map(Number);
        graph[u].push(v);
        graph[v].push(u);
    }
    function dfs(current, parent) {
        parents[current] = parent;
        for(const next of graph[current]) {
            if(next!==parent) {
                dfs(next,current);
            }
        }
    }
    dfs(1,0);

    for(let i = 2; i<=N;i++){
        console.log(parents[i]);
    }

});
