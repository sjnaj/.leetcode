/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */
// #include <unordered_map>
// #include <vector>
// using namespace std;
// @lc code=start
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        std::unordered_map<int, int> mp;
        int count = 0;
        for (int n1 : nums1)
        {
            for (int n2 : nums2)
            {
                ++mp[n1 + n2];
            }
        }
        for (int n3 : nums3)
        {
            for (int n4 : nums4)
            {
                if (mp.count(0 - n3 - n4) != 0)
                {
                    count += mp[0 - n3 - n4];
                }
            }
        }
        return count;
    }
};
// @lc code=end
