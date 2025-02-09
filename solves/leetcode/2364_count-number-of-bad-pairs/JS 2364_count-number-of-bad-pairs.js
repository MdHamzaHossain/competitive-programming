/**
 * @param {number[]} nums
 * @return {number}
 */
var countBadPairs = function (nums) {
    let counts = new Map();
    let bPairs = 0;
    for (let i = 0; i < nums.length; i++) {
        bPairs += i - (counts.get(i - nums[i]) ?? 0);
        counts.set(i - nums[i], (counts.get(i - nums[i]) ?? 0) + 1);
    }
    return bPairs;
};
