#include <bits/stdc++.h>

class Solution
{
public:
    std::unordered_map<int, int> mp;
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int sub = target - nums[i];
            if (mp.count(sub))
            {
                return {i, mp[sub]};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};