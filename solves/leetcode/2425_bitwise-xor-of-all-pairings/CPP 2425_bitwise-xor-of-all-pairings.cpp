function xorAllNums(nums1 : number[], nums2 : number[]) : number
{
    let res = 0;
    if (nums2.length % 2 == 1)
        nums1.forEach(e = > res ^= e);
    if (nums1.length % 2 == 1)
        nums2.forEach(e = > res ^= e);
    return res
};