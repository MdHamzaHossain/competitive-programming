// TODO
class Solution
{
public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        for (int &num : nums)
            num *= num;
        ranges::sort(nums);

        long long answer = 0;
        long long half = nums.size() / 2;

        for (int i = 0; i < half; ++i)
            answer -= nums[i];
        for (int i = half; i < nums.size(); ++i)
            answer += nums[i];
        return answer;
    }
};
