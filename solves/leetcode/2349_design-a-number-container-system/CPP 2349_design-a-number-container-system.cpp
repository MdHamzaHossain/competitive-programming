class NumberContainers
{

public:
    map<int, int> nums;
    map<int, set<int>> vals;
    NumberContainers()
    {
    }

    void change(int index, int number)
    {
        if (nums.count(index))
        {
            vals[nums[index]].erase(index);
            if (vals[nums[index]].size() == 0)
                vals.erase(nums[index]);
        }

        nums[index] = number;
        vals[number].insert(index);
    }

    int find(int number)
    {
        if (!vals.count(number))
            return -1;
        return *(vals[number].begin());
    }
};