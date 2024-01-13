/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode *root)
    {
        return isValid(root, nullptr, nullptr);
    }

    bool isValid(TreeNode *root, int *lower, int *upper)
    {
        if (root == nullptr)
        {
            return true;
        }
        //root->val 必须在lower和upper组成的开区间中
        if (lower && root->val <= *lower)
        {
            return false;
        }
        if (upper && root->val >= *upper)
        {
            return false;
        }
        return isValid(root->left, lower, &(root->val)) && isValid(root->right, &(root->val), upper);
    }
};
// @lc code=end
