/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <string>
#include <stack>
// @lc code=start
class Solution
{
public:
    bool isValid(std::string s)
    {
        if(s.size()%2!=0){
            return false;
        }
        std::stack<char> stk;
        for (char c : s)
        {
            if (c == '(')
            {
                stk.push(')');
            }
            else if (c == '[')
            {
                stk.push(']');
            }
            else if (c == '{')
            {
                stk.push('}');
            }
            else if (stk.empty() || c != stk.top())
            {
                return false;
            }
            else
            {
                stk.pop();
            }
        }
        return stk.empty();
    }
};
// @lc code=end
