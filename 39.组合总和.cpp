/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracing(int start, vector<int> &candidates, int sum, int target)
    {
        if (sum == target)
        {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size()&&sum+candidates[i] <=target; i++)
        {
            path.push_back(candidates[i]);
            backtracing(i, candidates, sum + candidates[i], target);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(),candidates.end());
        backtracing(0, candidates, 0, target);
        return res;
    }
};
// @lc code=end
