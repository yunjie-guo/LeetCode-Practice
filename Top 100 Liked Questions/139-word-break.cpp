class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        // store the dict into the set
        if(wordDict.size()==0) return false;
        
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        // dp[i] means the string from 0 to i can be broken into dict words
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    // 0-j-1
                    // j-i
                    // 0-i
                    string word = s.substr(j,i-j);
                    if(dict.find(word) != dict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};