/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

// @lc code=start
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
class Solution
{
public:
    // int countNodes(TreeNode* root) {
    //     if(root==nullptr){
    //         return 0;
    //     }
    //     return countNodes(root->left)+countNodes(root->right)+1;
    // }

    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int lh = 0, rh = 0;
        TreeNode *l = root,*r = root;
        while (l)
        {
            lh++;
            l = l->left;
        }
        while (r)
        {
            rh++;
            r = r->right;
        }
        if (rh == lh)
        {
            return pow(2, lh) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
// @lc code=end
