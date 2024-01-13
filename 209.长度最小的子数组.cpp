// @before-stub-for-debug-begin


using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include <vector>
// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int start=0,end=0,sum=0,len=__INT_MAX__;
        for(end=0;end<nums.size();end++){//i和j都最多移动n次，复杂度为n
            sum+=nums[end];
            while(sum>=target){
                if(end-start+1<len){
                    len=end-start+1;
                }
                sum-=nums[start++];
            }
        }
        if(len==__INT_MAX__){
            return 0;
        }
        return len;
    }
};
// int main(){
//     std::vector<int>a{2,3,1,2,4,3};
//     Solution s;
    
//     s.minSubArrayLen(7,a);

// }
// @lc code=end

