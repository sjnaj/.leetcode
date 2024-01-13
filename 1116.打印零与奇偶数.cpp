/*
 * @lc app=leetcode.cn id=1116 lang=cpp
 *
 * [1116] 打印零与奇偶数
 */
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <functional>
#include <thread>
#include <iostream>
#include <semaphore.h>
using namespace std;
// @lc code=start
class ZeroEvenOdd
{
    sem_t sem_z, sem_o, sem_e;
    atomic<int>n;
public:
    ZeroEvenOdd(int n)
    {
        this->n = n;
        sem_init(&sem_z, 0, 1);
        sem_init(&sem_o, 0, 0);
        sem_init(&sem_e, 0, 0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; i++)
        {
            sem_wait(&sem_z);
            printNumber(0);
            if (i % 2 == 0)
                sem_post(&sem_e);
            else
                sem_post(&sem_o);
        }
    }

    void even(function<void(int)> printNumber)
    {
        for (int i = 2; i <= n; i += 2)
        {
            sem_wait(&sem_e);
            printNumber(i);
            sem_post(&sem_z);
        }
    }

    void odd(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; i += 2)
        {
            sem_wait(&sem_o);
            printNumber(i);
            sem_post(&sem_z);
        }
    }
};
// @lc code=end

int main()
{
    ZeroEvenOdd z(10);
    cout << "start";
    std::thread t1{&ZeroEvenOdd::zero, &z, [](int i)
                   { cout << i; }};
    std::thread t2{&ZeroEvenOdd::odd, &z, [](int i)
                   { cout << i; }};
    std::thread t3{&ZeroEvenOdd::even, &z, [](int i)
                   { cout << i; }};
    t1.join();
    t2.join();
    t3.join();
}