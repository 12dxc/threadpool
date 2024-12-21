## 基于C++20的线程池
+ 有仅头文件和模块两种导入方式

### 使用方式

1. 提交单个任务

   ```c++
   Threadpool pool;
   pool.start(4);
   
   future<int> r1 = pool.submitTask(sum1, 1, 2);
   ```

2. 可自动并行的循环处理

   ```c++
   vector v{1, 2, 3, 4, 5};
   pool.submitLoop((size_t)0, v.size(),
                   [&v](auto &&i)
                   {
                       println("loop: {}", v.at(i));
                   });
   ```

   



