const MOD = 1e9 + 7;

let maxValue;
let sequenceLength;
let f;
let c;

function initializeSolution(n, mValue) {
    maxValue = mValue;
    sequenceLength = n;

    f = Array.from({ length: maxValue + 1 }, () => Array(16).fill(-1));
    c = Array.from({ length: n }, () => Array(16).fill(0));

    for (let i = 0; i < n; i++) {
        for (let j = 0; j <= i; j++) {
            if (j == 16) break;
            c[i][j] = j === 0 ? 1 : (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
}

function idealArrays(n, mValue) {
    initializeSolution(n, mValue);

    let res = 0;

    for (let i = 1; i <= maxValue; i++) res = (res + dfs(i, 1)) % MOD;
    return res;
}

function dfs(i, cnt) {
    if (f[i][cnt] !== -1) return f[i][cnt];
    let res = c[sequenceLength - 1][cnt - 1];
    if (cnt < sequenceLength) for (let k = 2; i * k <= maxValue; k++) res = (res + dfs(i * k, cnt + 1)) % MOD;
    f[i][cnt] = res;
    return res;
}
