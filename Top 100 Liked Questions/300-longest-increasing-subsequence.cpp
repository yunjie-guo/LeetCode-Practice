class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n,1);
        int ans = 1;
        for (int i = 1; i < n; ++i){
            for (int j = 0; j < i; ++j){
                // O(n^2)
                if (nums[i]>nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;   
    }
};

/*
[1,2,7,8,3,4,5,9,0]
1 -> [1]
2 -> [1,2]
7 -> [1,2,7]
8 -> [1,2,7,8]
3 -> [1,2,3,8]  // we replaced 7 with 3, since for the longest sequence we need only the last number and 1,2,3 is our new shorter sequence
4 -> [1,2,3,4] // we replaced 8 with 4, since the max len is the same but 4 has more chances for longer sequence
5 -> [1,2,3,4,5]
9 -> [1,2,3,4,5,9]
0 -> [0,2,3,4,5,9] // we replaced 1 with 0, so that it can become a new sequence
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v;
        if(nums.size()==0)
            return 0;
        v.push_back(nums[0]);
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>v[v.size()-1])
                v.push_back(nums[i]);
            else{
                auto it=lower_bound(v.begin(),v.end(),nums[i]);
                *it=nums[i];
            }
        }
        return v.size();
    }
};