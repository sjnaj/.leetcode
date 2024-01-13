// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem977.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
#include <vector>
// @lc code=start
class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::vector<int>res(nums.size());
        int left=0,right=nums.size()-1,index=right;
        while (left<=right)
        {
            int square_left=nums[left]*nums[left],square_right=nums[right]*nums[right];
            if(square_left>square_right){
                res[index--]=square_left;
                ++left;
            }else{
                res[index--]=square_right;
                --right;
            }
          
        }
        return res;
        
    }
};
// @lc code=end

