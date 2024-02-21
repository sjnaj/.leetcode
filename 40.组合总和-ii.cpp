/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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
        for (int i = start; i < candidates.size()&&sum+candidates[i]<=target; i++)//剪枝部分放在上面下标会越界
        {
            if (i > start && candidates[i] == candidates[i - 1])//不去重的话后面所取的集合必然和第一个包含candidates[i]的路径产生的集合重合
                continue;
            path.push_back(candidates[i]);
            backtracing(i + 1, candidates, sum + candidates[i], target);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        backtracing(0, candidates, 0, target);
        return res;
    }
};
// @lc code=end
