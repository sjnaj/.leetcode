/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

#include <queue>
// @lc code=start
class MyStack {
public:
    MyStack() {

    }
    std::queue<int>q;
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        for(int size=q.size();size>1;size--){
            q.push(q.front());
            q.pop();
        }
        int r=q.front();
        q.pop();
        return r;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

