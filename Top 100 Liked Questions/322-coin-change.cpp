class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if( coins.empty() ) return -1;
        vector<int> dp( amount + 1, INT_MAX );
        sort( coins.begin(), coins.end(), greater<int>() );
        dp[0] = 0;
        /*
        F(3)=min{F(3−c1),F(3−c2),F(3−c3)}+1
            =min{F(3−1),F(3−2),F(3−3)}+1
            =min{F(2),F(1),F(0)}+1
            =min{1,1,0}+1
            =1
        */
        for( auto coin : coins ){
            for( int i = coin; i <= amount; i++ )
                if( dp[i-coin] != INT_MAX )
                    dp[i] = min( dp[i], dp[i-coin] + 1 );
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};