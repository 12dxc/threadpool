#include <chrono>
#include <future>
#include <iostream>
#include <thread>

using namespace std;

#include "threadpool.hpp"

int sum1(int a, int b)
{
    this_thread::sleep_for(chrono::seconds(2));
    // 比较耗时
    return a + b;
}
int sum2(int a, int b, int c)
{
    this_thread::sleep_for(chrono::seconds(2));
    return a + b + c;
}
int main()
{
    Threadpool pool;
    pool.start(4);

    future<int> r1 = pool.submitTask(sum1, 1, 2);

    cout << r1.get() << endl;

    // 自动并行
    vector v{1, 2, 3, 4, 5};
    pool.submitLoop((size_t)0, v.size(),
                    [&v](auto &&i)
                    {
                        println("loop: {}", v.at(i));
                    });

    pool.submitBlocks((size_t)0, v.size(),
                      [&v](size_t begin, size_t end)
                      {
                          for (size_t i = begin; i < end; ++i)
                              println("block: {}", v.at(i));
                      });

    pool.submitSequence((size_t)0, v.size(),
                        [&v](auto &&i)
                        {
                            println("sequence: {}", v.at(i));
                        });

    getchar();
    return 0;
}