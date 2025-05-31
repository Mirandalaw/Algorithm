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
    const matrix = input.slice(1).map(row => row.split(' ').map(Number));
    const visited = Array.from({length: N}, () => Array(M).fill(false));
    const dx = [0, 0, -1, 1];
    const dy = [-1, 1, 0, 0];

    function dfs(start_x, start_y) {
        let painting = 1;
        visited[start_y][start_x] = true;
        for (let direction = 0; direction < 4; direction++) {
            const nx = start_x + dx[direction];
            const ny = start_y + dy[direction];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N && matrix[ny][nx] === 1 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                painting += dfs(nx, ny);
            }
        }
        return painting;
    }

    let maxPainting = 0;
    let paintingCnt = 0;

    for (let col = 0; col < N; col++) {
        for (let row = 0; row < M; row++) {
            if (!visited[col][row] && matrix[col][row] === 1) {
                paintingCnt++;
                let painting = dfs(row, col);
                if (painting > maxPainting) maxPainting = painting;
            }
        }
    }
    if(paintingCnt===0) maxPainting = 0;
    console.log(paintingCnt);
    console.log(maxPainting);
})