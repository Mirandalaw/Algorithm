const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let input = [];

rl.on("line", function (line) {
    input.push(line);
}).on("close", function () {
    const C = input[0].toString().split(" ").map(Number)[1];
    const house = input.slice(1).map(Number).sort((a, b) => a - b);
    // console.log(house);
    console.log(findMaxDistance(house, C));
    process.exit();
});


const canInstallRouter = (house, c, minDistance) => {
    let count = 1;
    let lastInstalled = house[0];

    for (let i = 1; i < house.length; i++) {
        if (house[i] - lastInstalled >= minDistance) {
            count++;
            lastInstalled = house[i];
        }
    }
    return count >= c;
}

const findMaxDistance = (house, c) => {
    let left = 1;
    let right = house[house.length - 1] - house[0]; // 최대 거리 후보
    let result = 0;
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (canInstallRouter(house, c, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}