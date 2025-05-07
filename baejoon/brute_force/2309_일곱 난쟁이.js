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
    const statures = input.map(Number);
    // let solve = Array.from({length: N});
    const arr = sevenDwarfs(statures,[]);
    for(let i=0; i<arr.length; i++){
        console.log(arr[i]);
    }
    process.exit();
});

function sevenDwarfs (statures, answer){
    let found = false;
    function dfs(picked, start,sum) {
        if(found) return ;
        if(picked.length=== 7){
            if(sum ===100) {
                answer.push(...picked);
                found = true;
                return;
            }
        }

        for(let i = start; i<statures.length; i++){
            picked.push(statures[i]);
            dfs(picked, i+1,sum+statures[i]);
            picked.pop();
        }

    }
    dfs([],0,0);
    return answer.sort((a,b) => {return a-b;});
}
