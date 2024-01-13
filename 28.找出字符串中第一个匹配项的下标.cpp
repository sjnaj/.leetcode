/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

#include <string>
#include <vector>
// @lc code=start
class Solution
{
public:
    std::vector<int> next;
    void initNext(std::string p)
    {
        next.reserve(p.size());

        next[0] = -1;
        int i = 0, j = -1; // 后缀指针，前缀指针
        while (i < p.size() - 1)
        {
            if (j == -1 || p[i] == p[j])
            {
                next[++i] = ++j; // 前缀表整体右移一位(第一位补-1，最后一位丢弃，因为不存在第len+1个字符失配），便于访问
            }
            else
            {
                j = next[j]; // 回退j
            }
        }
    }
    int strStr(std::string haystack, std::string needle)
    {
        initNext(needle);
        int j = 0, i = 0;
        while (i < haystack.size()&&j<(int)needle.size())//int与uint比较要转换
        {
            if (j == -1 || haystack[i] == needle[j])//同时步进
            {
                ++i;
                ++j;
            }
            else
            {
                j = next[j];//回退
            }
        }
        if (j == needle.size())//匹配成功
        {
            return i - j;
        }
        return -1;
    }
};
// @lc code=end

int main(){
    Solution s;
    s.strStr("hello","ll");
}
