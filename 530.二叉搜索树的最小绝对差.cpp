/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    TreeNode *prev = nullptr;
    int result = __INT_MAX__;

    void helper(TreeNode *curr)
    {
        if (!curr)
            return;
        helper(curr->left);
        if (prev&&curr->val - prev->val < result)
        {
            result = curr->val - prev->val;
        }
        prev = curr;
        helper(curr->right);
    }

    int getMinimumDifference(TreeNode *root)
    {
        helper(root);
        return result;
    }
};
// @lc code=end
