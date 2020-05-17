class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> s;
        vector<int> ans;
        // get the first k elements' maximum
        // nums = [1,3,-1,-3,5,3,6,7], and k = 3
        // for the first three
        // push index 0 into deque
        // index 1 is greater than index 0, pop index 0 and push index 1
        // index 2 is less than index 1, push index 2
        for (int i = 0; i < k; ++i){
            while (!s.empty() && nums[s.back()] <= nums[i]){
                s.pop_back();
            }
            s.push_back(i);
        }
        ans.push_back(nums[s.front()]);
        // descending stack
        for (int i = 1; i < nums.size()-k+1; ++i){
            if (i > s.front()){
                // pop the index out of the bounds
                s.pop_front();
            }
            while (!s.empty() && nums[i+k-1] > nums[s.back()]){
                s.pop_back();
            }
            s.push_back(i+k-1);
            ans.push_back(nums[s.front()]);    
        }
        return ans;
    }
};