class Solution {
public:
    int maxLength(vector<int>& nums) {
        int score = 0;
        int maxLength = 0;
        for(int i=0; i<nums.size() ;i++){
            int prod =nums[i];
            int GCD = nums[i];
            int LCM = nums[i];
            for(int j=i+1; j<nums.size(); j++){
                prod *= nums[j];
                GCD = gcd(GCD, nums[j]);
                LCM = nums[j] * LCM/GCD;
                cout <<" i " << i << " j " << j <<" PROD " << prod << " GCD " << GCD << " LCM " << LCM << " MAXLENGTH " << maxLength << endl;
                if(prod == LCM * GCD) {
                    score++;
                    maxLength = max(maxLength, j-i+1);
                    
                }
                if(prod > LCM * GCD){
                    
                    continue;
                }
            }
        }
        return maxLength;
    }
};