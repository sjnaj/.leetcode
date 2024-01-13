/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int res = 0;
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root != nullptr)
        {
            if (root->left && root->left->left == nullptr && root->left->right == nullptr)
            {
                res += root->left->val;
            }
            sumOfLeftLeaves(root->left);
            sumOfLeftLeaves(root->right);
        }
        return res;
    }
};
// @lc code=end
