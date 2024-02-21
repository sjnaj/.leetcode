/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
#include <vector>
using namespace std;
class Solution
{
public:
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int is, int ie, int ps, int pe)
    {
        if (is > ie)
        {
            return nullptr;
        }
        int val = postorder[pe];
        TreeNode *root = new TreeNode(val);
        // int pos;
        // for (int i = is; i <= ie; i++)
        // {
        //     if (inorder[i] == val)
        //     {
        //         pos = i;
        //         break;
        //     }
        // }
        int pos=std::find(inorder.begin()+is,inorder.begin()+ie,val)-inorder.begin();
        root->left = helper(inorder, postorder, is, pos - 1, ps, ps + pos - 1 - is);
        root->right = helper(inorder, postorder, pos + 1, ie, ps + pos - is , pe - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
// @lc code=end
