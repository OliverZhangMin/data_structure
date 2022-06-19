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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++)
            inorder_index[inorder[i]]=i;
        return build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
    TreeNode* build(vector<int>& inorder,vector<int>& postorder,int i_l,int i_r,int p_l,int p_r)
    {
        if(i_l > i_r || p_l > p_r)
            return nullptr;
        //1.后序遍历的最后一个元素是根节点
        auto root = new TreeNode(postorder[p_r]);
        //2.找到根节点，中序遍历中找到该节点所在的下标
        int mid = inorder_index[postorder[p_r]];
        int left_len = mid - i_l;
        int right_len = i_r - mid;
        //3.下标左边是当前根节点的左子树数据
        root->left  = build(inorder,postorder,i_l,mid-1,p_l,p_l+left_len-1);
        //4.下标右边的当前根节点的右子树数据
        root->right = build(inorder,postorder,mid+1,i_r,p_l + left_len,p_l+left_len+right_len-1);
        return root;
    }
    map<int,int> inorder_index;
};