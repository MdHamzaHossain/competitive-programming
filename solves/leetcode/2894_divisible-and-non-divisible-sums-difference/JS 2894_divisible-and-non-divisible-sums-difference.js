/**
 * @param {number} n
 * @param {number} m
 * @return {number}
 */
var differenceOfSums = function (n, m) {
    return Array.from({ length: n + 1 }, (a, i) => i).reduce((acc, curr) => acc + (curr % m ? curr : -curr), 0);
};
