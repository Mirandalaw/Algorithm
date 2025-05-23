const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
const N = Number(input[0]);
const A = input[1].split(' ').map(Number);
solve(A);
const lowerBound = (arr, target) => {
    let left = 0;
    let right = arr.length;

    while (left < right) {
        let mid = Math.floor((left + right) / 2);
        if (arr[mid] >= target) right = mid;
        else left = mid + 1;
    }
    return left;
};

const solve = (A) => {
    let LIS = [];

    for (const num of A) {
        let idx = lowerBound(LIS, num)
        if (idx === LIS.length) {
            LIS.push(num);
        } else {
            LIS[idx] = num;
        }
    }
    console.log(LIS.length);
}



