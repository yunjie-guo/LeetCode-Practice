static int __initialSetup = []() {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        // use quicksort to find the kth largest
        return find(nums, k, 0, nums.size() - 1);
    }

private:
    int find(vector<int>& nums, int k, int start, int end)
    {
        int m = partition(nums, start, end);
        if (nums.size() - m == k)
            return nums[m];
        if (nums.size() - m > k)
            return find(nums, k, m + 1, end);
        return find(nums, k, start, m - 1);
    }

    int partition(vector<int>& nums, int start, int end) {
        int random_index = start + rand() % (end - start + 1);
        swap(nums[random_index], nums[end]);
        int pivot = start;
        for (int i = start; i < end; ++i) 
            if (nums[i] <= nums[end]) 
                swap(nums[pivot++], nums[i]);
        swap(nums[pivot], nums[end]);
        return pivot;
    }
};