class Solution
{
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        bool overLap = false;
        const int
            aX1 = rec1[0],
            aY1 = rec1[1],
            aX2 = rec1[2],
            aY2 = rec1[3],
            bX1 = rec2[0],
            bY1 = rec2[1],
            bX2 = rec2[2],
            bY2 = rec2[3];

        if (bY2 > aY1 && bY1 < aY2 && bX1 < aX2 && bX2 > aX1)
            overLap = true;

        return overLap;
    }
};