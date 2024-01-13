/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <vector>
#include <deque>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        deque<int>q;//递减

        for(int i=0;i<nums.size();i++){
            //滑动窗口左边超过了最大值所处的位置
            while(!q.empty()&&q.front()<=i-k){
                q.pop_front();
            }
            //移除不可能成为最大值的元素位置
            while(!q.empty()&&nums[i]>=nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            //遍历到第一个窗口末尾开始添加最大值
            if(i>=k-1){
                res.push_back(nums[q.front()]);
            }
        }
        return res;

    }
};
// @lc code=end

