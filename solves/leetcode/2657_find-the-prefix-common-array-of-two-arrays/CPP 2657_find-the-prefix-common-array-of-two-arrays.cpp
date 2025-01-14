class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        vector<int> count = vector<int>(A.size() + 1, 0);
        unordered_set<int> uniques;
        vector<int> ans;
        int amounts = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (++count[A[i]] == 2)
                amounts++;
            if (++count[B[i]] == 2)
                amounts++;
            uniques.insert(A[i]);
            uniques.insert(B[i]);
            // int amount = 0;
            // if(count)
            // for (auto itr : uniques)
            // {
            //     if (count[itr] == 2)
            //         amount++;
            //     // else
            //     // {
            //     //     amount = 0;
            //     //     break;
            //     // }
            // }

            ans.push_back(amounts);
        }
        return ans;
    }
};