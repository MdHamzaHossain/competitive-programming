class Solution {
    public:
        string clearDigits(string s) {
            deque<char> dq;
            for(auto c: s){
                if(c >= '0' && c <= '9') {
                cout << c << endl;
    
                    if(dq.size() != 0) dq.pop_back();
                } else dq.push_back(c);
            }
            string s2 = "";
            for(auto e: dq) s2+= e;
            return s2;
        }
    };