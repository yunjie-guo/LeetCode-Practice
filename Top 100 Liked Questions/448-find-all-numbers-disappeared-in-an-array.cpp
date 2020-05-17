class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       for(int i = 0; i < nums.size(); i++)
       {
           int index = abs(nums[i]) - 1;
           if(nums[index] > 0)
               // hash table
               nums[index] *= -1;
       }
        
        vector<int> res;
        for(int i = 1; i <= nums.size(); i++)
        {
            if(nums[i-1] > 0)
                res.push_back(i);
        }
        
        return res;
        
    }
};