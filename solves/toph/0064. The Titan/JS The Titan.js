// NODEJS
const readline = require("readline").createInterface(process.stdin);
print = console.log;
readline.prompt();
readline.on("line", (line) => {
    solve(line);
    readline.close();
});

function solve(line) {
    let a = +line;
    let sum = 0;
    for (let i = 1; i <= a; i++) {
        sum += i * i;
    }
    console.log(sum);
}
