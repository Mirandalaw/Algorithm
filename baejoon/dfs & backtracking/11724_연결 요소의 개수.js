const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on("line", function (line) {
    input.push(line);
}).on("close", function () {
    const [N, M] = input[0].split(" ").map(Number);
    const graph = Array.from({ length: N + 1 }, () => []);
    const visited = Array(N + 1).fill(false);

    for (let i = 1; i <= M; i++) {
        const [u, v] = input[i].split(" ").map(Number);
        graph[u].push(v);
        graph[v].push(u);
    }

    function dfs(node) {
        visited[node] = true;
        for (const next of graph[node]) {
            if (!visited[next]) dfs(next);
        }
    }

    let count = 0;
    for (let i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }

    console.log(count);
});
