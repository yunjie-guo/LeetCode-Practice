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
    int ans;
    
    int depth(TreeNode* node){
        if (node==nullptr) return 0;
        int left = depth(node->left);
        int right = depth(node->right);
        ans = max(ans,left+right);
        return max(left,right)+1;
    }
    

    int diameterOfBinaryTree(TreeNode* root) {
        if (root==nullptr) return 0;
        depth(root);
        return ans;    
    }
};