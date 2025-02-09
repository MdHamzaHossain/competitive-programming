class Solution
{
public:
    vector<int> assignElements(vector<int> &groups, vector<int> &elements)
    {
        int mx = 100000;
        vector<int> tracker(groups.size(), -1);
        vector<int> minTrack(mx + 1, -1);

        for (int i = 0; i < elements.size(); i++)
        {
            if (minTrack[elements[i]] == -1)
                minTrack[elements[i]] = i;
        }
        for (int i = 0; i < groups.size(); i++)
        {
            int ans = -1;
            for (int divisor = 1; divisor * divisor <= groups[i]; divisor++)
            {
                int divGroup = groups[i] / divisor;
                if (groups[i] % divisor == 0)
                {
                    if (minTrack[divisor] != -1)
                    {
                        if (ans == -1 || minTrack[divisor] < ans)
                        {
                            ans = minTrack[divisor];
                        }
                    }
                    if (minTrack[divGroup] != -1)
                    {
                        if (ans == -1 || minTrack[divGroup] < ans)
                        {
                            ans = minTrack[divGroup];
                        }
                    }
                }
            }
            tracker[i] = ans;
        }
        return tracker;
    }
};