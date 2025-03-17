class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            vector<int> frequency(501, 0); 
            for (auto num : nums) {
                frequency[num]++;
            }
          
            for (auto e : frequency) {
                if (e % 2 != 0) {
                    return false;
                }
            }
            return true;
        }
    };