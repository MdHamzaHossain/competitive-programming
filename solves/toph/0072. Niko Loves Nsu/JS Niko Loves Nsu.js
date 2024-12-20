[a, b] = [(r = readline)(), r()];
[n, s, u] = ["N", "S", "U"].map((e) => b.match(new RegExp(e, "g"))?.length || 0);
print(Math.min(n, s, u));
