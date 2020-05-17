class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // ans[i] = right[i] * left[i];
        vector<int> left(nums.size(),1);
        vector<int> right(nums.size(),1);
        vector<int> ans(nums.size(),1);
        for (int i = 1; i < nums.size(); ++i){
            left[i] = nums[i-1] * left[i-1];
        }
        for (int i = nums.size()-2; i >= 0; --i){
            right[i] = nums[i+1] * right[i+1];
            ans[i] = right[i] * left[i];
        }
        ans[nums.size()-1] = left[nums.size()-1];
        return ans;
    }
};