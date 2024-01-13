/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
// #include <istream>
// using namespace std;
// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        std::vector<uint16_t> counts(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            ++counts[s[i] - 'a'];
            --counts[t[i] - 'a'];
        }
        for (int i = 0; i < 26; i++)
        {
            if (counts[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
