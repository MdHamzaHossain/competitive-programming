/**
 * @param {string} s
 * @param {string[][]} knowledge
 * @return {string}
 */
var evaluate = function (s, knowledge) {
    const mp = new Map(knowledge);
    return s.replace(/\(([^)]+)\)/gim, (m, p1) => mp.get(p1) || "?");
};
