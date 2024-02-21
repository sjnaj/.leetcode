/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    unordered_map<int, int> counts;
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        counts[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }

    vector<int> findMode(TreeNode *root)
    {

        if (!root)
            return {};
        dfs(root);
        vector<int> res;
        int maxCount = -1;
        for (auto item : counts)
        {
             if (item.second == maxCount)//可能有多个
            {
                res.push_back(item.first);
            }
            if (item.second > maxCount)
            {
                res = {item.first};
                maxCount=item.second;
            }
        }
        return res;
    }
};
// @lc code=end
