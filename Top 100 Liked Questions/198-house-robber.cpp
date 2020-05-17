class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        int house0 = nums[0];
        int hou0 = 0;
        int house1 = nums[1];
        int hou1 = house0;
        // similar to sell the stock
        // hou1 means break the house
        // house1 means not break the house
        for (int i = 2; i < nums.size(); ++i){
            int rob = max(hou1, max(hou0, house0)) + nums[i];
            int notrob = max(house1, hou1);
            house0 = house1;
            hou0 = hou1;
            house1 = rob;
            hou1 = notrob;
        }
        return max(house1, hou1);
    }
};