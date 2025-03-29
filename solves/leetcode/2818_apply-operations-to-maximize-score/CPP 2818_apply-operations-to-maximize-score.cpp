// bruhh
class Solution
{
public:
    static constexpr int kMod = 1000000007;

    long modPow(long x, long n)
    {
        if (n == 0)
            return 1;
        if (n % 2 == 1)
            return x * modPow(x % kMod, (n - 1)) % kMod;
        return modPow(x * x % kMod, (n / 2)) % kMod;
    }

    vector<int> sieveEratosthenes(int n)
    {
        vector<int> minPrims(n + 1);
        iota(minPrims.begin() + 2, minPrims.end(), 2);
        for (int i = 2; i * i < n; ++i)
            if (minPrims[i] == i)
                for (int j = i * i; j < n; j += i)
                    minPrims[j] = min(minPrims[j], i);
        return minPrims;
    }

    vector<int> getPrimeScores(const vector<int> &nums,
                               const vector<int> &minPrimeFactors)
    {
        vector<int> primeScores;
        for (const int num : nums)
            primeScores.push_back(getPrimeScore(num, minPrimeFactors));
        return primeScores;
    }

    int getPrimeScore(int num, const vector<int> &minPrimeFactors)
    {
        unordered_set<int> primeFactors;
        while (num > 1)
        {
            const int divisor = minPrimeFactors[num];
            primeFactors.insert(divisor);
            while (num % divisor == 0)
                num /= divisor;
        }
        return primeFactors.size();
    }
    int maximumScore(vector<int> &nums, int k)
    {
        const int n = nums.size();
        const int mx = ranges::max(nums);
        const vector<int> minPrimeFactors = sieveEratosthenes(mx + 1);
        const vector<int> primeScores = getPrimeScores(nums, minPrimeFactors);
        int ans = 1;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && primeScores[st.top()] <= primeScores[i])
                left[st.top()] = i, st.pop();
            st.push(i);
        }

        st = stack<int>();

        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && primeScores[st.top()] < primeScores[i])
                right[st.top()] = i, st.pop();
            st.push(i);
        }

        vector<pair<int, int>> numAndIndexes;

        for (int i = 0; i < n; ++i)
            numAndIndexes.emplace_back(nums[i], i);

        ranges::sort(numAndIndexes,
                     [&](const pair<int, int> &a, const pair<int, int> &b)
                     {
                         return a.first == b.first ? a.second < b.second : a.first > b.first;
                     });

        for (const auto &[num, i] : numAndIndexes)
        {
            const long rangeCount = static_cast<long>(i - left[i]) * (right[i] - i);
            const long actualCount = min(rangeCount, static_cast<long>(k));
            k -= actualCount;
            ans = static_cast<long>(ans) * modPow(num, actualCount) % kMod;
        }

        return ans;
    }
};