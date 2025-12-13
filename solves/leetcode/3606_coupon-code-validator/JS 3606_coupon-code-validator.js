/**
 * @param {string[]} code
 * @param {string[]} businessLine
 * @param {boolean[]} isActive
 * @return {string[]}
 */
function validateCoupons(code, businessLine, isActive) {
    const coupons = [];
    const prior = Object.freeze({
        electronics: 1,
        grocery: 2,
        pharmacy: 3,
        restaurant: 4,
    });

    const n = code.length;
    const prio = Array.from({ length: n }, () => 0);
    for (let i = 0; i < n; i++) {
        const p = prior[businessLine[i]];
        const c = code[i];
        if (c?.match(/^[a-zA-Z0-9_]+$/) && p && isActive[i]) {
            coupons.push(i);
            prio[i] = p;
        }
    }
    coupons.sort((a, b) => {
        if (prio[a] == prio[b]) return code[a] - code[b] ? -1 : 1;
        return prio[a] - prio[b];
    });
    delete prior;
    delete prio;
    delete code;
    delete businessLine;
    delete active;
    return coupons.map((a) => code[a]);
}
