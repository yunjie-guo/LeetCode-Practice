class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        int count = 0;
        for(auto i : tasks){
            mp[i-'A']++;
            count = max(count, mp[i-'A']);
        }
        
        int ans = (count-1)*(n+1);
        for(auto e : mp) {
            // idle slots
            if(e == count) ans++;
        }
        return max((int)tasks.size(), ans);
        
    }
};