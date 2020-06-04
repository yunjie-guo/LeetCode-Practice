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
    int count[10];
    int ans;
    void dfs(TreeNode* root){
        ++count[root->val];
        if (root->left) dfs(root->left);
        if (root->right) dfs(root->right);
        if (!root->left && !root->right){
            int odd_cnt = 0;
            for (int i = 0; i < 10; ++i)
                if (count[i] & 1) ++odd_cnt;
            if (odd_cnt <= 1) ++ans;
        }
        --count[root->val];
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
       if (!root) return 0;
       ans = 0;
       dfs(root); 
       return ans; 
    }
};