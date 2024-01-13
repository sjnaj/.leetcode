/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
#include <string>
using namespace std;
class Solution {
public:
vector<string>ans;
void helper(TreeNode*root,string curr){
    if(root==nullptr)return;
    if(root->left||root->right){
        curr+=(to_string(root->val)+"->");
        helper(root->left,curr);
        helper(root->right,curr);
    }
    else{
        curr+=to_string(root->val);
        ans.push_back(std::move(curr));
    }
}
    vector<string> binaryTreePaths(TreeNode* root) {
        helper(root,"");
        return ans;
    }
};
// @lc code=end

