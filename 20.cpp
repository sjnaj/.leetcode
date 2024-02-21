#include <bits/stdc++.h>
bool isValid(std::string s)
{
    if (s.size() % 2 != 0)
    {
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
            stk.push(c);
        }
    }
    return stk.empty();
}
