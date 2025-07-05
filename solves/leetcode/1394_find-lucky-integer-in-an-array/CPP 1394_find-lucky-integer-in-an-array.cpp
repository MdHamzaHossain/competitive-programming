
class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        vector<int> v(501, 0);
        for (auto e : arr)
            v[e]++;
        int res = -1;
        for (int i = v.size() - 1; i > 0; i--)
        {

            cout << v[i] << endl;
            if (v[i] == i)
            {
                res = i;
                break;
            }
        }
        return res;
    }
};