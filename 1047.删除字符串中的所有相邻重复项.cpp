/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution
{
public:
    string removeDuplicates(string s)
    {
        int i = 0; // 栈顶位置，初始一个元素
        int j = 1;

        while (j < s.size())
        {

            if (i < 0 || s[i] != s[j])
            {
                s[++i] = s[j++];
            }
            else
            {
                i--;
                j++;
            }
        }
        return s.substr(0, i + 1);//i多减了一次
    }
}
;
// @lc code=end
