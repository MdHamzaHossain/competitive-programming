class Solution
{
public:
    bool isTrionic(const vector<int> &nums)
    {
        /**
         * 0 initial
         * 1 inc
         * 2 dec
         * 3 inc (desired state)
         * 4 invalid
         */
        int state = 0;

        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (prev == curr)
                state = 4;

            if (state == 4)
                break;
            int curr = nums[i];
            switch ((state))
            {
            case 0:
                if (curr > prev)
                    state++;
                else
                    state = 4;
                break;
            case 1:
                if (curr < prev)
                    state++;
                break;
            case 2:
                if (curr > prev)
                    state++;
                break;
            case 3:
                if (curr < prev)
                    state++;
                break;

            default:
                break;
            }
            prev = nums[i];
        }
        return state == 3;
    }
};