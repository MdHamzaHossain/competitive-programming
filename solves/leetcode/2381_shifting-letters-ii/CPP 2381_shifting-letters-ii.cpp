class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {

        // vector<int> charIntVec;
        // for (char c : s)
        // {
        //     charIntVec.push_back(c - 'a');
        // }
        vector<int> changeIndexCounter = vector<int>(s.size() + 1, 0);
        for (int i = 0; i < shifts.size(); i++)
        {
            int l = shifts[i][0];
            int r = shifts[i][1];
            // Convert 0 and 1 to -1,1.. Note: Look for bit operations
            int dir = shifts[i][2] ? 1 : -1;
            changeIndexCounter[l] += dir;
            changeIndexCounter[r + 1] -= dir;
        }
        string res = "";
        int accumulator = 0;
        for (int i = 0; i < s.length(); i++)
        {
            accumulator = (changeIndexCounter[i] + accumulator) % 26;
            // Min must be 26
            res += ('a' + ((s[i] - 'a' + accumulator + 26) % 26));
        }
        return res;
    }
};
/**
* VERSION 2
class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {

        vector<int>charIntVec;
        for (char c : s)
        {
            charIntVec.push_back(c-'a');
        }
        for (int i = 0; i < shifts.size(); i++)
        {
            int l = shifts[i][0];
            int r = shifts[i][1];
            int dir = shifts[i][2];
            // this needs optimizing
            transform(charIntVec.begin() + l, charIntVec.begin() + r+1, charIntVec.begin() + l, [&dir](int a)
                      {
                         int z= dir ? a+1:a-1;
                         if(z <0) z = 26+z;
                         else if(z>25) z= z-26;
                         return z;
                       });


        }
        string res="";
        for(int i:charIntVec) {
            //char c = (i<0 ? '{'+i: 'a'+ (i>25)?25-i:i);

            res+=('a'+i);
        };
        return res;
    }
};
*/