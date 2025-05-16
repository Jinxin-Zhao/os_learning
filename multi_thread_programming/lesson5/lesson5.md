# 程序的顺序执行假设
+ 两个线程sum++的例子：
1. -O1: R[eax] = sum; R[eax] += N; sum = R[eax]
2. -O2: sum += N

another example
    ```c
    while(!done);
    // would be optimized to 
    if (!done) while(1); //直接死循环
    ```

+ 保证执行顺序
C状态和汇编状态机的“可观测行为等价”
方法1: 插入“不可优化”代码
    asm volatile ("" ::: "memory")
方法2: 标记变量load/store为不可优化
    使用volatile变量
    ```c
    extern int volatile done;
    while (!done);
    ```

example:
    ```c
    void Tsum() {
        int t = x;
        asm volatile("" ::: "memory");  // 需要重新从reg加载x，如果没有语句，则下面一行会被优化直接删掉
        t = x;
    }
    ```

# 处理器间的可见性
example:
    ```c
    int x = 0, y = 0;
    void T1() {
        x = 1; // store x
        __sync_synchronize();
        printf("%d", y); // load y
    }

    void T2() {
        y = 1; // store y
        __sync_synchronize();
        printf("%d", x); // load x
    }
    // 遍历模型结果理论上是 01，10，11
    // 但实际上有可能会有00，原因是有可能多核CPU在进行数据加载时，从cache中加载x和y的时候，有可能x在CPU1上，y在CPU2上，导致cache miss，然后两个CPU在一个时钟周期内同时load x和y速度非常快，读取速度大于存储速度，就会导致00
    ```

# 宽松内存模型（Relaxed/Weak Memory Model）
+ 目的是使单处理器的执行更高效，x86已经是市面上能买到的最强的内存模型了。
但ARM/RISC-V本质上是一个分布式系统。