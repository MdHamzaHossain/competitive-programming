class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int prevValue = 0;
        int max = 0;
        int maxInd;
        for(int i = 0; i < events.size(); i++){
            int key = events[i][0];
            int value = events[i][1];

            int x = value - prevValue;
            prevValue = value;
            if(x > max) {
                max = x;
                maxInd = key;
            } else if (x == max && maxInd > key) maxInd = key;
        }
        return maxInd;

    }
};