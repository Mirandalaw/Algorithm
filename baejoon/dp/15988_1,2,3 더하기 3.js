const fs = require("fs");

const MOD = 1000000009;
const input = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let idx = 0;

const T = input[idx++];
const ns = [];
let maxN = 0;
for (let i = 0; i < T; i++) {
    const n = input[idx++];
    ns.push(n);
    if (n > maxN) maxN = n;
}

// dp[n] = dp[n-1] + dp[n-2] + dp[n-3] (mod MOD)
// 베이스: dp[0]=1, dp[1]=1, dp[2]=2
const dp = new Array(Math.max(3, maxN + 1)).fill(0);
dp[0] = 1;
dp[1] = 1;
dp[2] = 2;
for (let i = 3; i <= maxN; i++) {
    const sum = (dp[i - 1] + dp[i - 2]) % MOD;
    dp[i] = (sum + dp[i - 3]) % MOD;
}

let out = "";
for (const n of ns) out += dp[n].toString() + "\n";
console.log(out.trim());