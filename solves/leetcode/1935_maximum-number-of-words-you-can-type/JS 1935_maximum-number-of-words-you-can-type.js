/**
 * @param {string} text
 * @param {string} brokenLetters
 * @return {number}
 */
function canBeTypedWords(text, brokenLetters) {
    const words = text.split(" ");
    let c = 0;
    for (const word of words) {
        const w = word.split("").find((a) => brokenLetters.includes(a));
        if (!w) c++;
    }
    return c;
}
