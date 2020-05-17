class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        size_t n = nums.size();
        vector<int> temp(1000+1+1000, 0);
        vector<vector<int>> dp(n, temp);
        dp[0][nums[0]+1000] = 1;
        dp[0][-nums[0]+1000] += 1; // 1000 is the offset
        for (size_t i = 1; i < n; ++i){
            for (int j = -1000; j <= 1000; ++j){
                if (dp[i-1][j+1000]>0){
                  dp[i][j+1000-nums[i]] += dp[i-1][j+1000];
                  dp[i][j+1000+nums[i]] += dp[i-1][j+1000];                    
                }
            }
        }
        return S > 1000 ? 0 : dp[n-1][S+1000];
    }
};