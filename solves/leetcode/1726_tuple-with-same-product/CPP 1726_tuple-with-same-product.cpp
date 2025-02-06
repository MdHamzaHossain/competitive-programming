class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int res = 0;
        map<int, int> tracker;

        for(int i =0; i<nums.size(); i++) {
            for(int j=0; j < i; j++) {
                res += tracker[nums[i]*nums[j]]++ * 8;
            }
        }
        return res;
    }
};