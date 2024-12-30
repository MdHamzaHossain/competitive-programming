t = +(r = readline)();
while (t--) {
    [n, k] = r()
        .split(" ")
        .map((a) => +a);
    let arr = r()
        .split(" ")
        .map((a) => +a)
        .sort((a, b) => a - b);
    let valid = true;
    for (let i = 0; i < arr.length; i++) {
        if (i != arr.length - 1 && arr[i + 1] - arr[i] > k) {
            valid = false;
            break;
        }
    }
    if (!valid) {
        print("No Solution");
        continue;
    }
    print(arr.join(" "));
}
