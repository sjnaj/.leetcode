/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracing(int k, int n, int start, int sum)
    {

        if (path.size() == k)
        {
            if (sum == n)
                res.push_back(path);
            return;
        }
        if (path.size() != 0 && path.back() + sum >= n)
            return;
        for (int i = start; i + k - path.size() - 1 <= 9; i++)
        {
            path.push_back(i);
            backtracing(k, n, i + 1, sum + i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        path.reserve(k);
        backtracing(k, n, 1, 0);
        return res;
    }
};
// @lc code=end
