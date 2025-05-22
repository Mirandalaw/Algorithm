const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let input = [];

rl.on("line", function (line) {
    input.push(line);
}).on("close", function () {

    const N  = input[0].toString().split(" ").map(Number)[0];
    const M  = input[0].toString().split(" ").map(Number)[1];
    const tree = input[1].toString().split(" ").map(Number);
    console.log(findMaxHeight(tree,M));

    process.exit();
});

const isEnough = (height,tree,m) =>{
    return tree.reduce((acc,tree) => acc + (Math.max(0,tree - height)),0) >=m;
}

const findMaxHeight = (tree, m) =>{
    let left = 0 ;
    let right = Math.max(...tree);
    let result = 0 ;
    while(left<=right) {
        let mid = Math.floor((left+right)/2);
        if(isEnough(mid,tree,m)){
            result = mid;
            left = mid +1;
        } else{
            right = mid -1;
        }
    }
    return result;
}