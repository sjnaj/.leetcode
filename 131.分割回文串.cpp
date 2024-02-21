/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

#include <string>

using namespace std;
// @lc code=start
class Solution
{
public:
    bool isValid(string const &s, int start, int end)
    {
        while (start < end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
    vector<vector<string>> res;
    vector<string> path;
    void backtracing(string const &s, int start)
    {
        if (start == s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++)
        {
            if (isValid(s, start, i))
            {
                path.push_back(s.substr(start, i - start + 1));
                backtracing(s, i + 1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        backtracing(s, 0);
        return res;
    }
};
// @lc code=end
