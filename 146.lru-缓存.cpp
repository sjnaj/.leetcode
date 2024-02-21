/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

#include <list>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class LRUCache
{
public:
    list<pair<int, int>> li;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    int count;
    LRUCache(int capacity) : count(capacity)
    {
    }

    int get(int key)
    {
        if (map.count(key) != 0)
        {
            li.splice(li.begin(), li, map[key]);
            return map[key]->second;
        }
        return -1;
    }

    void put(int key, int value)
    {

        if (get(key) != -1)
        {
            map[key]->second = value;
            return;
        }
        else if (li.size() == count)
        {
            map.erase(li.back().first);
            li.pop_back();
        }
        li.push_front({key, value});
        map[key] = li.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
