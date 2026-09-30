// TODO
class Solution
{
public:
    vector<int> maxDepthAfterSplit(string seq)
    {
        int sequenceLength = seq.size();
        vector<int> result(sequenceLength);
        int currentDepth = 0;
        for (int i = 0; i < sequenceLength; ++i)
        {
            if (seq[i] == '(')
            {
                result[i] = currentDepth & 1;
                currentDepth++;
            }
            else
            {
                currentDepth--;
                result[i] = currentDepth & 1;
            }
        }

        return result;
    }
};
