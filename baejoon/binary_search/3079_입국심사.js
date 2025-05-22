const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let input = [];

rl.on("line", function (line) {
    input.push(line);
}).on("close", function () {
    const N = input[0].toString().split(" ").map(Number)[1];
    const time = input.slice(1).map(line => Number(line.trim()));

    console.log(screeningTable(time,N));
    process.exit();
});

const canScreen = (times, n, limit) =>{
    let count = 0 ;
    for(const time of times){
        count +=Math.floor(limit/time);
        if (count >= n) return true;
    }
    return false;
}
const screeningTable =(time, n) =>{
    let left = BigInt(1);
    let right = BigInt(n * Math.max(...time));
    let result = 0 ;
    while(left<=right){
        let mid = Math.floor((left+right)/2);
        if(canScreen(time,n,mid)){
            result = mid;
            right = mid -1;
        } else {
            left = mid +1;
        }
    }
    return result;
}