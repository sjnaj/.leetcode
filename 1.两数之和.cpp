/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution {
public:
    std::unordered_map<int,int> map;
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
        {
            int s=target-nums[i];
            if(map.find(s)!=map.end())
            return {map[s],i};
            map.insert({nums[i],i});
            
        }
        return {};
        
    }
};
// @lc code=end

