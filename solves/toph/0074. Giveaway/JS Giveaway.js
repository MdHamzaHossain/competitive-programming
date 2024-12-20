[a, b] = [(r = readline)(), r()];
let subFound = false;
for (const c of a.split("")) {
    if (b.includes(c)) {
        subFound = true;
        break;
    }
}
print(subFound ? "YES" : "NO");
