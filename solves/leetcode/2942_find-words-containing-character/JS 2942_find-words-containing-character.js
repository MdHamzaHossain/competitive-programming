/**
 * @param {string[]} words
 * @param {character} x
 * @return {number[]}
 */
function findWordsContaining(words, x) {
    let arr = [];
    words.forEach((a, b) => (a.includes(x) ? arr.push(b) : undefined));
    return arr;
}
