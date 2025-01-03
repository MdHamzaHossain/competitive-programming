//* Final
#define ll long long
class Solution
{
public:
    ll waysToSplitArray(vector<int> &nums)
    {
        ll count = 0;
        ll total = accumulate(nums.begin(), nums.end(), 0ll);
        /**
         * if i get the total, going from the back, i need to check if,
         * total - sumFromTheBack >= sumFromTheBack, then increment
         * swap that around,
         * total >= 2* sumFromTheBack
         */
        ll sumFromTheBack = 0;
        for (ll i = nums.size() - 1; i > 0; i--)
        {
            sumFromTheBack += nums[i];
            if (total >= 2 * sumFromTheBack)
                count++;
        }

        return count;
    }
};

// ! Version 2 after looping from the back, check count condition immediately
// #define ll long long
// class Solution {
// public:
//     ll waysToSplitArray(vector<int>& nums) {
//         vector<int>scoresBack;
//         vector<ll>scores= vector<ll>(nums.size()+1, 0);
//         vector<ll>scoresFront = vector<ll>(nums.size(), 0);
//         // int fromTheBack = nums[nums.size()-1];
//         ll fromTheBack = 0;
//         //llint fromTheFront = nums[nums.size()-1];
//         ll fromTheFront = 0;
//         // empty element to account for.. idk man
//         //scores.push_back(0);
//         // scoresBack.push_back(0);
//         ll count=0;
//         for(ll i=0; i<nums.size(); i++){
//             fromTheBack += nums[i];
//             scores[i+1] += fromTheBack;
//             // scoresBack.push_back(fromTheBack);
//             // scoresFront[nums.size()-1-i] -= fromTheFront;
//         }
//         for(ll i=nums.size()-1; i >= 1; i--){
//             fromTheFront += nums[i];
//             scores[i] -= fromTheFront;
//             if(scores[i] > -1) count++;
//         }
//         return count;
//     }
// };

// ! Version 1
// #define ll long long
// class Solution {
// public:
//     ll waysToSplitArray(vector<int>& nums) {
//         vector<int>scoresBack;
//         vector<ll>scores= vector<ll>(nums.size()+1, 0);
//         vector<ll>scoresFront = vector<ll>(nums.size(), 0);
//         // int fromTheBack = nums[nums.size()-1];
//         ll fromTheBack = 0;
//         //llint fromTheFront = nums[nums.size()-1];
//         ll fromTheFront = 0;
//         // empty element to account for.. idk man
//         //scores.push_back(0);
//         // scoresBack.push_back(0);
//         ll count=0;
//         for(ll i=0; i<nums.size(); i++){
//             fromTheBack += nums[i];
//             scores[i+1] += fromTheBack;
//             // scoresBack.push_back(fromTheBack);
//             fromTheFront += nums[nums.size()-1-i];
//             scores[nums.size()-1-i] -= fromTheFront;
//             // scoresFront[nums.size()-1-i] -= fromTheFront;
//         }
//         for(ll i=1; i < scores.size()-1; i++){
//             cout << " BACK " << scores[i] << " front "  << endl;
//             if(scores[i] > -1) count++;
//            // if(scoresBack[i] >= scoresFront[i]) count++;
//         }
//         return count;
//     }
// };

/*
 ! Test Case generator Scripts

 copy('['+Array.from({length:100000}, () => -10000).join(', ') + ']')

 copy('['+Array.from({length:100000}, () => 100000-Math.floor(Math.random() * 200000)).join(', ') + ']')
 */