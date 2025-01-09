/**
 * @param {string[]} words
 * @param {string} pref
 * @return {number}
 */
const prefixCount = function (words, pref) {
    return words.reduce((a, c) => {
        if (c.startsWith(pref)) a++;
        return a;
    }, 0);
};
