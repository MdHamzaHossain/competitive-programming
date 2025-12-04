class Solution
{
public:
    int countCollisions(const string &directions)
    {
        int contRs = directions[0] == 'R';
        char prev = directions[0];
        int tot = 0;
        for (int i = 1; i < directions.size(); i++)
        {
            const char c = directions[i];
            if (c == 'R')
                contRs++;
            if (prev == 'R')
            {
                if (c != 'R') // Collision!
                    tot += contRs + (c == 'L') /* 2 collisions if they're coming from the opposite*/,
                        contRs = 0, prev = 'S' /* The current vehicle is stopped */;
            }
            else if (prev == 'S' && c == 'L') // Collision!
                tot++, prev = 'S' /* The current vehicle is stopped */;
            else
                prev = c;
        }
        return tot;
    }
};