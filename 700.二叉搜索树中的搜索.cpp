/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    // TreeNode *searchBST(TreeNode *root, int val)
    // {
    //     if (!root)
    //     {
    //         return nullptr;
    //     }
    //     if (root->val == val)
    //     {
    //         return root;
    //     }
    //     return val < root->val ? searchBST(root->left, val) : searchBST(root->right, val);
    // }
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root)
        {
            if (val < root->val)
            {
                root = root->left;
            }
            else if (val > root->val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
        return nullptr;
    }
};
// @lc code=end
