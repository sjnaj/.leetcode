/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path; // 共用一个

    constexpr size_t fact(int n)
    {
        size_t res=1;
        for(int i=2;i<=n;i++){
            res*=i;
        }
        return res;
    }

    void backtracing(int k, int n, int start)
    {
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }
        for (int i = start; i + k - path.size() - 1 <= n; i++)
        {
            path.push_back(i);
            backtracing(k, n, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        // res.reserve(std::tgamma(n + 1) / (std::tgamma(n - k + 1) * std::tgamma(k + 1)));
        res.reserve(fact(n) / (fact(n - k) * fact(k)));
        path.reserve(k);
        backtracing(k, n, 1);
        return res;
    }
};
// @lc code=end
