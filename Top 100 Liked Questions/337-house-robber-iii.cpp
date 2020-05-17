/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) 
    {
        std::pair<int, int> m = helper(root);
        return std::max(m.first, m.second);
    }
    
    std::pair<int, int> helper(TreeNode* root)
    {
        if(!root) return {0, 0};
        
        auto leftMoney = helper(root->left);
        auto rightMoney = helper(root->right);
        
        return {root->val + leftMoney.second + rightMoney.second,
                std::max(leftMoney.first, leftMoney.second) 
                + std::max(rightMoney.first, rightMoney.second)};
    }
};