/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include <vector>
// @lc code=start
class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, middle ;
        while (left <= right)
        {
            middle = (left + right) / 2;
            if (target < nums[middle])
            {
                right = middle - 1;
            }
            else if (target > nums[middle])
            {
                left = middle + 1;
            }
            else
            {
                return middle;
            }
        }
        return -1;
    }
};
// @lc code=end
