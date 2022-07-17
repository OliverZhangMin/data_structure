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
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_path;
    }
    int dfs(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int left_path  = max(0,dfs(root->left));
        int right_path = max(0,dfs(root->right));
        max_path = max(max_path,root->val + left_path + right_path);
        return max(left_path,right_path) + root->val;
    }
    int max_path = -1e9;
};