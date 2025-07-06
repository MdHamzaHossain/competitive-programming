class FindSumPairs
{
public:
    vector<int> n1;
    vector<int> n2;
    unordered_map<int, int> counter;
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        this->n1 = nums1;
        this->n2 = nums2;

        for (int e : nums2)
            counter[e]++;
    }

    void add(int index, int value)
    {
        int oldValue = n2[index];
        counter[oldValue]--;
        counter[oldValue + value]++;
        n2[index] += value;
    }

    int count(int total)
    {
        int pairs = 0;
        for (int e : n1)
            pairs += counter[total - e];

        return pairs;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */