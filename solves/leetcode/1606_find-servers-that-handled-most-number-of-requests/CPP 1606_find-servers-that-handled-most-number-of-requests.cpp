// TODO
class Solution
{
public:
    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load)
    {

        set<int> availableServers;
        for (int i = 0; i < k; ++i)
        {
            availableServers.insert(i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busyServers;

        vector<int> requestCount(k);

        for (int i = 0; i < arrival.size(); ++i)
        {
            int startTime = arrival[i];
            int endTime = startTime + load[i];

            while (!busyServers.empty() && busyServers.top().first <= startTime)
            {
                availableServers.insert(busyServers.top().second);
                busyServers.pop();
            }

            if (availableServers.empty())
            {
                continue;
            }

            auto iterator = availableServers.lower_bound(i % k);
            if (iterator == availableServers.end())
            {

                iterator = availableServers.begin();
            }

            int selectedServer = *iterator;
            ++requestCount[selectedServer];
            busyServers.emplace(endTime, selectedServer);
            availableServers.erase(selectedServer);
        }

        int maxRequests = *max_element(requestCount.begin(), requestCount.end());

        vector<int> result;
        for (int i = 0; i < k; ++i)
        {
            if (requestCount[i] == maxRequests)
            {
                result.push_back(i);
            }
        }

        return result;
    }
};
