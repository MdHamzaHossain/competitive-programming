readline();
console.log(
    readline()
        .split(" ")
        .reduce((a, b) => (+b > +a ? b : a), 0),
);
