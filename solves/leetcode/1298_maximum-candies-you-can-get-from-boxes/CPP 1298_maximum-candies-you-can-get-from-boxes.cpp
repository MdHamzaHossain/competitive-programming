class Solution
{
public:
    int maxCandies(vector<int> &statuses, vector<int> &candies, vector<vector<int>> &keys, vector<vector<int>> &containedBoxes, vector<int> &initialBoxes)
    {
        int tots = 0;
        int numBoxes = statuses.size();
        vector<bool> hasB(numBoxes, false);
        vector<bool> openedB(numBoxes, false);
        queue<int> remaining;

        for (int boxId : initialBoxes)
        {
            hasB[boxId] = true;
            if (statuses[boxId])
            {
                tots += candies[boxId];
                openedB[boxId] = true;
                remaining.push(boxId);
            }
        }

        while (!remaining.empty())
        {
            int currentBoxId = remaining.front();
            remaining.pop();

            for (int key : keys[currentBoxId])
            {
                statuses[key] = 1;
                if (hasB[key] && !openedB[key])
                {
                    tots += candies[key];
                    openedB[key] = true;
                    remaining.push(key);
                }
            }

            for (int containedBox : containedBoxes[currentBoxId])
            {
                hasB[containedBox] = true;

                if (statuses[containedBox] && !openedB[containedBox])
                {
                    tots += candies[containedBox];
                    openedB[containedBox] = true;
                    remaining.push(containedBox);
                }
            }
        }

        return tots;
    }
};