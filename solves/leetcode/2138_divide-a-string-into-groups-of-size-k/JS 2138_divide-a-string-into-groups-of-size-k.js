/**
 * @param {string} s
 * @param {number} k
 * @param {character} fill
 * @return {string[]}
 */
export const divideString = function (s, k, fill) {
    const myArr = [];
    let tString = "";
    for (let i = 0; i < s.length; i++) {
        tString += s[i];
        if (tString.length == k) {
            myArr.push(tString);
            tString = "";
        }
    }
    while (tString.length != 0) {
        if (tString.length == k) {
            myArr.push(tString);
            tString = "";
        } else {
            tString += fill;
        }
    }
    return myArr;
};
