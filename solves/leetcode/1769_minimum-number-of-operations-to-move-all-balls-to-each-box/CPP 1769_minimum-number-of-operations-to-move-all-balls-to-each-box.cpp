class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int boxAmountFromTheLeft = 0;
        vector<int> movesLeft;
        int moves = 0;

        for (int i = 0; i < boxes.size(); i++)
        {
            // if(!moves && boxAmountFromTheLeft) moves=1;
            moves += boxAmountFromTheLeft;
            if (boxes[i] == '1')
            {
                boxAmountFromTheLeft++;
            }

            movesLeft.push_back(moves);
        }
        moves = 0;
        boxAmountFromTheLeft = 0;
        for (int i = boxes.size() - 1; i > -1; i--)
        {
            moves += boxAmountFromTheLeft;
            if (boxes[i] == '1')
            {
                boxAmountFromTheLeft++;
            }
            movesLeft[i] += moves;
        }
        return movesLeft;
    }
};