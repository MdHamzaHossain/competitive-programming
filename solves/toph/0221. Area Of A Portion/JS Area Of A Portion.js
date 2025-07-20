t = +(r = readline)();
while (t--) {
    let [a, b] = r()
        .split(" ")
        .map((a) => +a);

    print((a * a + b * b) * (b / a - Math.atan(b / a)));
}
