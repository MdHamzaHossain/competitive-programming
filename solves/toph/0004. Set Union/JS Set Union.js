[n, m] = (r = readline)()
    .split(" ")
    .map((e) => +e);
[a, b] = [r, r].map((e) =>
    e()
        .split(" ")
        .map((e1) => +e1),
);
c = new Set(a.concat(b).sort((a1, b1) => a1 - b1));
print(Array.from(c).join(" "));
