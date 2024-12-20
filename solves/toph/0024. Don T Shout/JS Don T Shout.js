console.log(
    readline()
        .split(" ")
        .filter((a) => a.toUpperCase() != a)
        .join(" "),
);
