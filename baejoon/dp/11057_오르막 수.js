// BOJ 11057
const fs = require("fs");

const n = Number(fs.readFileSync(0, "utf8").trim());
const MOD = 10007;

function solve(n) {
    // dp[d] = 길이 현재 n에서 "마지막 자리가 d"인 오르막 수의 개수
    const dp = Array(10).fill(1); // n=1일 때 각 d마다 1개

    for (let len = 2; len <= n; len++) {
        for (let d = 0; d <= 9; d++) {
            if (d === 0) {
                dp[d] %= MOD;
            } else {
                // dp[len][d] = dp[len-1][d] + dp[len][d-1]
                dp[d] = (dp[d] + dp[d - 1]) % MOD;
            }
        }
    }

    // 총 개수 = 마지막 자리가 0..9인 경우의 수의 합
    const ans = dp.reduce((acc, v) => (acc + v) % MOD, 0);
    console.log(ans);
}

solve(n);
