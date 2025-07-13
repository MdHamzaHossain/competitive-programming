class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        sort(trainers.begin(), trainers.end());
        sort(players.begin(), players.end());

        int matches = 0;
        int trainerCount = 0;
        for (int playuh : players)
        {
            while (trainerCount < trainers.size() && trainers[trainerCount] < playuh)
                trainerCount++;

            if (trainerCount < trainers.size())
                matches++,
                    trainerCount++;
        }

        return matches;
    }
};