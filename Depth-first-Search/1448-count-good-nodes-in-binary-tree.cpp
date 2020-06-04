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
    int ans;
    
    void dfs(TreeNode* p, int n){
        if (p->val >= n) ++ans;
        if (p->right){
            dfs(p->right, max(n,p->right->val));
        }
        if (p->left){
            dfs(p->left, max(n,p->left->val));
        }
    }
    
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        ans = 0;
        dfs(root, root->val);
        return ans;
    }
};