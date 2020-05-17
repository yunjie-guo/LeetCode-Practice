class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for (int i = 0; i < nums.size(); ++i){
            // move all none zero elements to the front
            if (nums[i]!=0){
                int temp = nums[pos];
                nums[pos] = nums[i];
                nums[i] = temp;
                ++pos;
            }
        }
    }
};