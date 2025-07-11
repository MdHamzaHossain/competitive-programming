// TODO
#define ll long long
#define roomPair pair<ll, int>

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        priority_queue<roomPair, vector<roomPair>, greater<roomPair>> occupiedRooms;

        for (int i = 0; i < n; ++i)
        {
            availableRooms.push(i);
        }

        vector<int> bookingCount(n, 0);

        sort(meetings.begin(), meetings.end());

        for (auto &meeting : meetings)
        {
            ll startTime = meeting[0];
            ll endTime = meeting[1];

            while (!occupiedRooms.empty() && occupiedRooms.top().first <= startTime)
            {
                availableRooms.push(occupiedRooms.top().second);
                occupiedRooms.pop();
            }

            int roomIndex;
            if (!availableRooms.empty())
            {

                roomIndex = availableRooms.top();
                availableRooms.pop();
                occupiedRooms.push({endTime, roomIndex});
            }
            else
            {

                auto nextAvailableRoom = occupiedRooms.top();
                occupiedRooms.pop();
                roomIndex = nextAvailableRoom.second;
                occupiedRooms.push({nextAvailableRoom.first + (endTime - startTime), roomIndex});
            }

            bookingCount[roomIndex]++;
        }

        int mostBookedRoomIndex = 0;
        for (int i = 0; i < n; ++i)
        {
            if (bookingCount[mostBookedRoomIndex] < bookingCount[i])
            {
                mostBookedRoomIndex = i;
            }
        }
        return mostBookedRoomIndex;
    }
};
