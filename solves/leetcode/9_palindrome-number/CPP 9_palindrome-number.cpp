class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        long long rev = 0;
        long long y = x;
        while (y)
        {
            rev = rev * 10 + (y % 10);
            y /= 10;
        }
        return rev == x;
    }
};
/**
 *!  ORIGINAL APPROACH
 class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        bool pal = true;
        int size = s.size();
        for(int i = 0;i < s.size(); i++){
            if(s[size-1-i] != s[i]) {
                pal=false; break;
            }
        }
        return pal;
    }
};

 */