/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
#include <stack>
class Solution
{
public:
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        std::stack<std::pair<TreeNode *, bool>> s;
        std::vector<int> res;
        TreeNode *n;
        bool accessible;
        s.push({root, false});
        while (!s.empty())
        {
            n = s.top().first;
            accessible=s.top().second;
            s.pop();
            if (n)//探测到非空结点
            {
                if (accessible)
                {
                    res.push_back(n->val);
                }
                else
                {
                    s.push({n->right, false});
                    s.push({n, true});//允许访问val
                    s.push({n->left, false});
                }
            }
            
        }
        return res;
    }
};

// @lc code=end
