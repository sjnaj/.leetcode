/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include <string>
#include <stack>
#include <vector>
// @lc code=start
class Solution
{
public:
    int evalRPN(std::vector<std::string> &tokens)
    {
        std::stack<int> s;
        int op1, op2;
        for (std::string c : tokens)
        {
            if (c == "+" || c == "-" || c == "*" || c == "/")
            {
                op2 = s.top();
                s.pop();
                op1 = s.top();
                s.pop();
                if (c == "+")
                    s.push(op1 + op2);
                else if (c == "-")
                    s.push(op1 - op2);
                else if (c == "*")
                    s.push(op1 * op2);
                else
                    s.push(op1 / op2);
            }
            else
            {
                s.push(stoi(c));
            }
        }
        return s.top();
    }
};
// @lc code=end

int main(){
    Solution s;
    std::vector<std::string>v{"-1","-1","-"};
    s.evalRPN(v);
}
