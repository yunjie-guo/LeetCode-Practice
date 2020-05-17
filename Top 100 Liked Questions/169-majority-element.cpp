class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ans = 0;
        // Boyer-Moore Voting Algorithm
        for (int i = 0; i < nums.size(); ++i){
            if (count == 0){
                ans = nums[i];
            }
            if (ans==nums[i]){
                ++count;
            }
            else{
                --count;
            }
        }
        return ans;
    }
};