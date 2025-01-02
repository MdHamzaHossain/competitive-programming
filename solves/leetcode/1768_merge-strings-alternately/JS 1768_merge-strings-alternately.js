/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
const mergeAlternately = function (word1, word2) {
    let s = "";
    for (let i = 0; i < Math.max(word1.length, word2.length); i++) {
        if (word1[i]) s += word1[i];
        if (word2[i]) s += word2[i];
    }
    return s;
};
