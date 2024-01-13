/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */
#include <string>
#include <vector>
// @lc code=start
class Solution
{
public:
    // bool repeatedSubstringPattern(std::string s) // kmp法
    // {
    //     int j = -1, i = 0;
    //     std::vector<int> next(s.size()+1);//需要整个串的最长相等前后缀
    //     next[0] = -1;
    //     while (i < s.size())
    //     {
    //         if (j == -1 || s[i] == s[j])
    //         {
    //             next[++i] = ++j;
    //         }
    //         else
    //         {
    //             j = next[j];
    //         }
    //     }
    //     return next.back()!=0&&(s.size() % (s.size() - next.back())==0);//判断是否可以整除除去最长前/后缀(非空)剩余部分（生成子串）
    // }
      bool repeatedSubstringPattern(std::string s) // 移动匹配
    {
        std::string t=s+s;//2s=3p
        t.erase(t.end()-1);
        t.erase(t.begin());
        return t.find(s)!=-1;//在中间找p

    }
};
// @lc code=end
