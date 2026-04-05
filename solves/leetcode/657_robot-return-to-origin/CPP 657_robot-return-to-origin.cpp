class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int posX = 0;
        int posY = 0;
        for (auto &e : moves)
        {
            if (e == 'U')
                posY++;
            else if (e == 'D')
                posY--;
            else if (e == 'L')
                posX--;
            else if (e == 'R')
                posX++;
        }
        return posY == posX && posX == 0;
    }
};