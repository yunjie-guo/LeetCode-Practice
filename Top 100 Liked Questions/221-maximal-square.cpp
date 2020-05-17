class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    
        int rows = matrix.size();
        if(rows ==0)
            return 0;
        int cols = matrix[0].size();
        int maxSq = 0;
        vector<int> dp(cols, 0);
        int prev = 0;
        // dp[i][j] = max(dp[i-1][j],dp[i-1][j-1],dp[i][j-1]) + 1
        for(int i=0;i<rows;++i)
        {  
            for(int j=0; j<cols;++j)
            {
                int temp = dp[j];
                if(matrix[i][j] == '1')
                {
                    if(i==0 || j==0)
                        dp[j] = 1;
                    else
                        dp[j] = min(dp[j-1], min(prev, dp[j])) + 1;
                    maxSq = max(maxSq, dp[j]);
                }else
                    dp[j] = 0;
                prev = temp;
            }
        }

        return maxSq*maxSq;
    }
};