/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function (nums) {
    const tol = nums.reduce((acc, curr) => acc + curr, 0);

    if (tol % 2 !== 0) return false;

    const targetSum = tol >> 1;

    const keep = Array.from({ length: targetSum + 1 }, () => false);
    keep[0] = true;

    for (const num of nums) for (let j = targetSum; j >= num; --j) keep[j] = keep[j] || keep[j - num];

    return keep[targetSum];
};
