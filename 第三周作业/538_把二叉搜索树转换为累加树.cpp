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
    int cur_sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        TreeNode* cur_root = new TreeNode;
        cur_root->right = convertBST(root->right);
        cur_sum += root->val;
        cur_root->val = cur_sum;
        cur_root->left = convertBST(root->left);
        return cur_root;
    }
};