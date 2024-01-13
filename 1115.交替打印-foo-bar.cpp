/*
 * @lc app=leetcode.cn id=1115 lang=cpp
 *
 * [1115] 交替打印 FooBar
 */
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <functional>
using namespace std;
// @lc code=start
class FooBar
{
private:
    int n;
    mutex mtx;
    condition_variable cv;
    atomic<bool> flag;

public:
    FooBar(int n)
    {
        this->n = n;
        this->flag = true;
    }

    void foo(function<void()> printFoo)
    {
        for (int i = 0; i < n; i++)
        {

            std::unique_lock<mutex> lk(mtx);
            cv.wait(lk, [&]
                    { return flag == true; });//wait函数设置了谓词(Predicate)，只有当pred条件为false时调用该wait函数才会阻塞当前线程
            flag = !flag;
            printFoo();
            lk.unlock();//也可以等待自动unlock，但是在notify之前释放效率略高一些
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar)
    {

         for (int i = 0; i < n; i++)
        {

            std::unique_lock<mutex> lk(mtx);
            cv.wait(lk, [&]
                    { return flag == false; });
            flag = !flag;
            printBar();
            lk.unlock();
            cv.notify_one();
        }
    }
};
// @lc code=end
