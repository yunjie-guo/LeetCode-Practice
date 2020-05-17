class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // https://leetcode.com/problems/shortest-unsorted-continuous-subarray/solution/
        // determine the correct position of the minimum and the maximum element
        // in the unsorted subarray to determine the boundaries of the required unsorted subarray
        int shortest = 0; 
        int left = 0, right = nums.size() - 1;
        while (left < nums.size() - 1 && nums[left] <= nums[left + 1]) { left++; }
        while (right > 0 && nums[right] >= nums[right - 1]) { right--; };
        
        if (right > left) {
            int vmin = INT_MAX, vmax = INT_MIN;
            for (int i = left; i <= right; ++i) {
                if (nums[i] > vmax) {
                    vmax = nums[i];
                }
                if (nums[i] < vmin) {
                    vmin = nums[i];
                }
            }
            
            while (left >= 0 && nums[left] > vmin) { left--; };
            while (right < nums.size() && nums[right] < vmax) { right++; };
            
            shortest = right - left - 1;
        }
        
        return shortest;
    }
};