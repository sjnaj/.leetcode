/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
// #include <vector>
// using std::vector;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        for (int i = 0; i < sz - 3; i++)
        {
            // 去重，越过相等区间的第一个元素之后的部分
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            // 剪枝
            if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
            {
                break;
            }
            if ((long long)nums[i] + nums[sz - 1] + nums[sz - 2] + nums[sz - 3] < target)
            {
                continue;
            }
            for (int j = i + 1; j < sz - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                {
                    break;
                }
                if ((long long)nums[i] + nums[j] + nums[sz - 1] + nums[sz - 2] < target)
                {
                    continue;
                }
                int left = j + 1, right = sz - 1;
                while (left < right)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum < target)
                    {
                        left++;
                    }
                    else if (sum > target)
                    {
                        right--;
                    }
                    else
                    {
                        auto tuple = vector<int>{nums[i], nums[j], nums[left], nums[right]};
                        res.emplace_back(tuple);
                        while (left < right && nums[left] == tuple[2])
                        {
                            left++;
                        }
                        while (right > left && nums[right] == tuple[3])
                        {
                            right--;
                        }
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
