/**
 * @param {number[]} nums
 * @param {number} limit
 * @return {number[]}
 */
const lexicographicallySmallestArray = function (nums, limit) {
    let len = nums.length;
    const ind = [...nums.keys()];
    ind.sort((a, b) => nums[a] - nums[b]);
    const res = Array.from({ length: len }, () => 0);
    for (let i = 0; i < len; ) {
        let j = i + 1;
        while (j < len && nums[ind[j]] - nums[ind[j - 1]] <= limit) j++;
        const temp = ind.slice(i, j).sort((a, b) => a - b);
        for (let k = i; k < j; k++) res[temp[k - i]] = nums[ind[k]];
        i = j;
    }
    return res;
};
