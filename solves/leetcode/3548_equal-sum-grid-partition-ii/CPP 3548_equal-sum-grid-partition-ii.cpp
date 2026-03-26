// TODO
//  I hate this so much. what even is a connected section?? like i can only cut out the corners?
/**
#define ll long long
class Solution
{
public:
    bool canPartitionGrid(vector<vector<int>> &grid)
    {

        ll sum = 0;
        const ll r = grid.size();
        const ll c = grid[0].size();
        ll mx = 0;
        for (ll i = 0; i < r; i++)
        {
            for (ll j = 0; j < c; j++)
            {
                sum += grid[i][j];
                mx = max(mx, (ll)grid[i][j]);
            }
        }


        ll sum2 = 0;
        unordered_set<ll> st;
        st.insert(grid[0][0]);
        st.insert(grid[0][c - 1]);
        st.insert(grid[r - 1][0]);
        st.insert(grid[r - 1][c - 1]);
        cout << "DEBUG " << grid[0][0] << ' ';
        for(auto e: st) cout << e << ' ';
        cout << endl;
        for (ll i = 0; i < r; i++)
        {
            for (ll j = 0; j < c; j++)
            {
                sum2 += grid[i][j];
            }
           cout << "deb " << sum2 - sum << endl;
            if (sum- sum2 == sum2)
                return true;
            if (st.contains(abs(sum - 2 * sum2)))
                return true;
            if (sum - 2 * sum2 > mx)
                break;
        }
        sum2 = 0;
        for (ll i = r - 1; i >= 0; i--)
        {
            for (ll j = c - 1; j >= 0; j--)
            {
                sum2 += grid[i][j];
            }
            cout << "deb " << sum2 - sum << endl;
            if (sum- sum2 == sum2)
                return true;
            if (st.contains(abs(sum - 2 * sum2)))
                return true;
            if (sum - 2 * sum2 > mx)
                break;
        }
        sum2 = 0;
        // for (ll i = 0; i < c; i++)
        // {

        //     for (ll j = 0; j < r; j++)
        //     {
        //         sum2 += grid[j][i];
        //         st.insert((ll)grid[i][j]);
        //     }
        //     cout << sum2 << ' ' << sum << endl;
        //     if (sum2 == sum)
        //         return true;
        //     if (st.contains(sum2 - sum))
        //         return true;
        //     if (sum2 - sum > mx)
        //         break;
        // }

        return false;
    }
};
*/
class Solution
{
public:
    bool canPartitionGrid(vector<vector<int>> &grid)
    {
        return check(grid) || check(rotate(grid));
    }

private:
    bool check(const vector<vector<int>> &g)
    {
        int m = g.size(), n = g[0].size();
        long long s1 = 0, s2 = 0;

        unordered_map<long long, int> cnt1, cnt2;

        for (auto &row : g)
        {
            for (int x : row)
            {
                s2 += x;
                cnt2[x]++;
            }
        }

        for (int i = 0; i < m - 1; i++)
        {
            for (int x : g[i])
            {
                s1 += x;
                s2 -= x;
                cnt1[x]++;
                cnt2[x]--;
            }

            if (s1 == s2)
                return true;

            if (s1 < s2)
            {
                long long diff = s2 - s1;
                if (cnt2[diff] > 0)
                {
                    if (
                        (m - i - 1 > 1 && n > 1) || (i == m - 2 && (g[i + 1][0] == diff || g[i + 1][n - 1] == diff)) || (n == 1 && (g[i + 1][0] == diff || g[m - 1][0] == diff)))
                        return true;
                }
            }
            else
            {
                long long diff = s1 - s2;
                if (cnt1[diff] > 0)
                {
                    if (
                        (i + 1 > 1 && n > 1) || (i == 0 && (g[0][0] == diff || g[0][n - 1] == diff)) || (n == 1 && (g[0][0] == diff || g[i][0] == diff)))
                        return true;
                }
            }
        }

        return false;
    }

    vector<vector<int>> rotate(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> t(n, vector<int>(m));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                t[j][i] = grid[i][j];
            }
        }
        return t;
    }
};