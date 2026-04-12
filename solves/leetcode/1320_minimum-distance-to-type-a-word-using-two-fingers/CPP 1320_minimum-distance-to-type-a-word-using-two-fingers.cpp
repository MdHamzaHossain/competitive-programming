// TODO
class Solution
{
public:
    int minimumDistance(string word)
    {
        int wordLength = word.size();
        const int INF = 1 << 30;

        vector<vector<vector<int>>> dp(wordLength,
                                       vector<vector<int>>(26,
                                                           vector<int>(26, INF)));

        for (int otherFinger = 0; otherFinger < 26; ++otherFinger)
        {
            dp[0][word[0] - 'A'][otherFinger] = 0;
            dp[0][otherFinger][word[0] - 'A'] = 0;
        }

        for (int i = 1; i < wordLength; ++i)
        {
            int prevChar = word[i - 1] - 'A';
            int currChar = word[i] - 'A';
            int moveDist = dist(prevChar, currChar);

            for (int otherFinger = 0; otherFinger < 26; ++otherFinger)
            {

                dp[i][currChar][otherFinger] = min(dp[i][currChar][otherFinger],
                                                   dp[i - 1][prevChar][otherFinger] + moveDist);

                dp[i][otherFinger][currChar] = min(dp[i][otherFinger][currChar],
                                                   dp[i - 1][otherFinger][prevChar] + moveDist);

                if (otherFinger == prevChar)
                {

                    for (int prevOtherFinger = 0; prevOtherFinger < 26; ++prevOtherFinger)
                    {
                        int otherFingerDist = dist(prevOtherFinger, currChar);

                        dp[i][currChar][otherFinger] = min(dp[i][currChar][otherFinger],
                                                           dp[i - 1][prevOtherFinger][prevChar] + otherFingerDist);

                        dp[i][otherFinger][currChar] = min(dp[i][otherFinger][currChar],
                                                           dp[i - 1][prevChar][prevOtherFinger] + otherFingerDist);
                    }
                }
            }
        }

        int minDistance = INF;
        int lastChar = word[wordLength - 1] - 'A';

        for (int otherFinger = 0; otherFinger < 26; ++otherFinger)
        {
            minDistance = min(minDistance, dp[wordLength - 1][lastChar][otherFinger]);
            minDistance = min(minDistance, dp[wordLength - 1][otherFinger][lastChar]);
        }

        return minDistance;
    }

    int dist(int keyA, int keyB)
    {
        int rowA = keyA / 6, colA = keyA % 6;
        int rowB = keyB / 6, colB = keyB % 6;
        return abs(rowA - rowB) + abs(colA - colB);
    }
};
