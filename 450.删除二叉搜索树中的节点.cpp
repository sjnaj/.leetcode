/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 */

// @lc code=start
/* *
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
private:
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root)
        {
            if (key < root->val)
            {
                root->left = deleteNode(root->left, key);
            }
            else if (key > root->val)
            {
                root->right = deleteNode(root->right, key);
            }
            else
            {
                if (!root->left && !root->right)
                {
                    delete root;
                    root=nullptr;
                }
               else if (!root->left || !root->right)
                {
                    TreeNode *temp = root;
                    root = root->left ? root->left : root->right;
                    delete temp;
                }
                else // 左子树右下角结点移到根结点
                {
                    TreeNode *temp = root->left;
                    while (temp->right)
                    {
                        temp = temp->right;
                    }
                    root->val = temp->val;
                    root->left = deleteNode(root->left, root->val);
                }
            }
        }
        return root;
    }
};
// @lc code=end
