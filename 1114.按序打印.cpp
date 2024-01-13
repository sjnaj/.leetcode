/*
 * @lc app=leetcode.cn id=1114 lang=cpp
 *
 * [1114] 按序打印
 */
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <functional>
using namespace std;
// @lc code=start
class Foo
{
    atomic<int> cur;
    mutex mtx;
    condition_variable cv;

public:
    Foo()
    {
        this->cur = 1;
    }

    void do_work(function<void()> printS, int num)
    {
        unique_lock<mutex> lk(mtx);
        cv.wait(lk, [&]
                { return cur == num; });
        printS();
        cur++;
        cv.notify_all();
    }

    void first(function<void()> printFirst)
    {

        // printFirst() outputs "first". Do not change or remove this line.
        do_work(printFirst, 1);

        // unique_lock<mutex> lk(mtx);
        // cv.wait(lk, [&]
        //         { return cur == 1; });
        // printFirst();
        // cur++;
        // cv.notify_all();
    }

    void second(function<void()> printSecond)
    {

        // printSecond() outputs "second". Do not change or remove this line.
        do_work(printSecond, 2);
    }

    void third(function<void()> printThird)
    {

        // printThird() outputs "third". Do not change or remove this line.
        do_work(printThird, 3);
    }
};
// @lc code=end
