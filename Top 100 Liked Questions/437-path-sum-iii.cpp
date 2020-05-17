/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int helper(TreeNode* node, int current, int sum){
        if (!node) return 0;
        return (current+node->val == sum) + helper(node->right, current+node->val, sum) + helper(node->left, current+node->val, sum);
        
    }
    
    
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return helper(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};