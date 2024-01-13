/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <vector>
// @lc code=start
class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int slow=0;
        for(int fast=0;fast<nums.size();fast++){
            if(nums[fast]!=val){
                nums[slow++]=nums[fast];
            }
        }
        return slow;
    }
};
// @lc code=end

