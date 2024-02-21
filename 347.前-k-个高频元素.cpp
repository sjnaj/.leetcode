/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{

public:
    // 默认less，大顶堆

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int num : nums)
        {
            map[num]++;
        }
        vector<int> res;
        // priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;小根堆
        priority_queue<pair<int,int>>pq;
        for (auto it = map.begin(); it != map.end(); it++)
        {
            pq.push({it->second, it->first});
            if (pq.size() > map.size() - k)
            {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};
// @lc code=end
