class Solution {
    public:
        int maximumSum(vector<int>& numbers) {
            vector<vector<int>> sumGroups(100);
          
            for (int& n : numbers) {
                int sum = 0;
                for (int value = n; value > 0; value /= 10) {
                    sum += value % 10;
                }
                sumGroups[sum].emplace_back(n);
            }
          
            int mx = -1; 
            for (auto& g : sumGroups) {
                if (g.size() > 1) {
                    sort(g.rbegin(), g.rend());
                    mx = max(mx, g[0] + g[1]);
                }
            }
            return mx;
        }
    };