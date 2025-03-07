class Solution
{
public:
    vector<bool> stieve(int n)
    {
        vector<bool> primeTrackers(n, true);
        primeTrackers[0] = false;
        primeTrackers[1] = false;
        for (int i = 2; i * i < n; i++)
            if (primeTrackers[i])
                for (int j = i * i; j < n; j += i)
                    primeTrackers[j] = false;
        return primeTrackers;
    }
    vector<int> closestPrimes(int left, int right)
    {
        vector<bool> primes = stieve(right + 10);
        vector<int> resPrime;
        for (int i = left; i <= right; i++)
        {
            if (primes[i])
                resPrime.push_back(i);
        }
        if (resPrime.size() < 2)
            return {-1, -1};
        int lowDiff = right + 2;
        int a, b;
        for (int i = 0; i < resPrime.size() - 1; i++)
        {
            if ((resPrime[i + 1] - resPrime[i] < lowDiff))
            {
                lowDiff = resPrime[i + 1] - resPrime[i];
                a = resPrime[i];
                b = resPrime[i + 1];
            }
        }
        return {a, b};
    }
};