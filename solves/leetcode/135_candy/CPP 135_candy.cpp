
class Solution
{
public:
    int candy(vector<int> &ratings)
    {

        int chiles = ratings.size();

        vector<int> lCand(chiles, 1);
        vector<int> rCand(chiles, 1);

        for (int i = 1; i < chiles; ++i)
            if (ratings[i] > ratings[i - 1])
                lCand[i] = lCand[i - 1] + 1;

        for (int i = chiles - 2; i >= 0; --i)
            if (ratings[i] > ratings[i + 1])
                rCand[i] = rCand[i + 1] + 1;

        int tots = 0;
        for (int i = 0; i < chiles; ++i)
            tots += max(lCand[i], rCand[i]);

        return tots;
    }
};
