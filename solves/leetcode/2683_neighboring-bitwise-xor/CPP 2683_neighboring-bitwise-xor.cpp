class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        int answer = 0;
        for (int i = 0; i < derived.size(); i++)
        {
            answer = answer ^ derived[i];
        }
        return answer == 0;
    }
};