// TODO
class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {

        ranges::sort(asteroids);

        long long currentMass = mass;

        for (int asteroidMass : asteroids)
        {

            if (currentMass < asteroidMass)
            {
                return false;
            }

            currentMass += asteroidMass;
        }

        return true;
    }
};
