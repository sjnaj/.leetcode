/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (count == g.size())
            {
                return count;
            }
            if (g[count] <= s[i])
            {
                count++;
            }
        }
        return count;
    }
};
// @lc code=end
