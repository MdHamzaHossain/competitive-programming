class Solution
{
public:
    int countPartitions(const vector<int> &nums)
    {
        const unsigned char n = nums.size();

        bitset<101> setSums;         // 100 indexes, represents the prefix sum's parity on each index
        auto tempSum = setSums[100]; // instead of a new boolean, add an extra bit
        tempSum = 0;                 // prefix sum parity

        unsigned char i = 0;
        for (i; i < n; i++)
            tempSum = (tempSum + nums[i] & 1 /* just the parity */) & 1,
            setSums[i] = tempSum; // store in the bitset

        tempSum = 0; // reset

        for (i = n - 1; i > 0; i--) // from the back
        {
            setSums[i] = !(tempSum ^ setSums[i]);      // XNOR, if both are odd (1) then the difference will be even, same for evens (0)
            tempSum = ((tempSum + (nums[i] & 1)) & 1); // update after to follow the partiiton and to not have an overlap
        }
        // reset the bits unused in the result to not interfere
        setSums[0] = 0;
        tempSum = 0;
        // return the amount of 1s in the bitset
        return setSums.count();
    }
};