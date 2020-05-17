class Solution {
public:
    int i = 0;
    string decode(string s) {
        string res;
        while (i < s.length() && s[i] != ']'){
            if (!isdigit(s[i])){
                res += s[i];
                ++i;
            } else {
                // get the total number
                int n = 0;
                while (i < s.size() && isdigit(s[i])){
                    n = n * 10 + s[i] - '0';
                    ++i;
                }
                // omit the '['
                ++i;
                string center = decode(s);
                // omit the ']'
                ++i;
                while (n > 0){
                    res += center;
                    --n;
                }
            }
        }
        return res;
    }
    
    
    
    string decodeString(string s) {
        return decode(s);
    }
};