/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// #include <vector>
// #include <algorithm>
// using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int left, right;
        for (int i = 0; i < sz; i++)
        {
            if (nums[i] > 0)
                break;
            if(i>0&&nums[i]==nums[i-1]){//去重i
                continue;
            }
            left = i + 1;
            right = sz - 1;
            while (left < right)
            {

                if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else
                {
                    vector<int> tuple{nums[i], nums[left], nums[right]};
                    res.emplace_back(tuple);
                    // 去重left和right
                    while (left < right && nums[left] == tuple[1])
                    {
                        left++;
                    }
                    while (right > left && nums[right] == tuple[2])
                    {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
