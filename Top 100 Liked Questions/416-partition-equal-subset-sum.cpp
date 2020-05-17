class Solution {
private:
    bool dfs(vector<int>& nums, int idx, int target) {
        if (target<0) return false;
        if (target==0) return true;
        for (int i=idx; i<nums.size(); i++) {
            if (target-nums[i]<0) break; // sort the nums
            if (dfs(nums,i+1,target-nums[i])) return true;
        }
        return false;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        sort(nums.rbegin(),nums.rend()); // sort the nums
        return sum%2==0 && dfs(nums,0,sum/2);
    }
};