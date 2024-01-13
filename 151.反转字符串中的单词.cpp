/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> ans;
        stringstream ss(s);
        string token;
        while (ss >> token)
        {
            ans.push_back(token);
        }
        reverse(ans.begin(), ans.end());
        token = "";
        for (string s : ans)
        {
            token += s;
            token += " ";
        }
        token.pop_back(); // 退出最后的空格
        return token;
    }
};
// @lc code=end
