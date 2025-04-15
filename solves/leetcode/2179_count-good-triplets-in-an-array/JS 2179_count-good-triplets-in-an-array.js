let tree = [];
let size = 0;

function initBinaryIndexedTree(n) {
    size = n;
    tree = new Array(n + 1).fill(0);
}

function update(index, delta) {
    while (index <= size) {
        tree[index] += delta;
        index += lowbit(index);
    }
}

function query(index) {
    let sum = 0;
    while (index > 0) {
        sum += tree[index];
        index -= lowbit(index);
    }
    return sum;
}

function lowbit(x) {
    return x & -x;
}

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
function goodTriplets(nums1, nums2) {
    let n = nums1.length;
    let position = new Array(n);
    for (let i = 0; i < n; ++i) {
        position[nums2[i]] = i + 1;
    }

    initBinaryIndexedTree(n);
    let count = 0;

    for (let num of nums1) {
        let currentPos = position[num];
        let leftCount = query(currentPos);
        let rightCount = n - currentPos - (query(n) - query(currentPos));
        count += leftCount * rightCount;
        update(currentPos, 1);
    }
    return count;
}
