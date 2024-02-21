/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isValid(string const &s)
    {
        if (s.empty())
        {
            return false;
        }
        if (s[0] == '0' && s.size() == 1)
        {
            return true;
        }
        if (s[0] == '0' || s.size() > 3)
        {
            return false;
        }
        return stoi(s) <= 255;
    }
    vector<string> res;
    vector<string> path;
    string numString;
    void backtracing(string const &s, int start, int count)
    {
        if (count == 3)
        {
            numString = s.substr(start, s.size() - start + 1);
            if (isValid(numString))
            {

                res.push_back(path[0] + "." + path[1] + "." + path[2] + "." + numString);
            }
            return;
        }
        for (int i = start; i < s.size(); i++)
        {
            numString = s.substr(start, i - start + 1);
            if (isValid(numString))
            {
                path.push_back(numString);
                backtracing(s, i + 1, count + 1);
                path.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        backtracing(s, 0, 0);
        return res;
    }
};
// @lc code=end
