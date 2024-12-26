let readline = require("readline").createInterface(process.stdin);
print = console.log;
readline.prompt();
readline.on("line", (line) => {
    solve(line);
    readline.close();
});

function solve(line) {
    [a, b] = line.split(" ");
    print(Math.floor((+a * +b) / 2));
}
