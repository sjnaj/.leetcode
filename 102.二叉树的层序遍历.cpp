/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start

// Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
#include <vector>
#include <queue>
class Solution
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        std::vector<std::vector<int>> res;
        std::queue<TreeNode *> q;
        TreeNode *t;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            res.emplace_back(sz);//原地构造
            for (int i = 0; i < sz; i++)
            {
                t = q.front();
                q.pop();
                res.back()[i]=t->val;
                if (t->left != nullptr)
                {
                    q.push(t->left);
                }
                if (t->right != nullptr)
                {
                    q.push(t->right);
                }
            }
        }
        return res;
    }
};
// @lc code=end
