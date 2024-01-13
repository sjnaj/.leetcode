/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */
// #include <vector>
// #include <unordered_set>
// using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> sets(nums1.begin(), nums1.end());
        vector<int> res;
        for (int num : nums2)
        {
            // if (sets.find(num)!=sets.end())
            if(sets.count(num)!=0)
            {
                res.push_back(num);
                sets.erase(num);//去重
            }
        }
        return res;
    }
};
// @lc code=end
