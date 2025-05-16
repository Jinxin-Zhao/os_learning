#include "lesson5.h"

// 这两个数组被标记为volatile,意味着它们的值可能会在程序的不同部分（例如多个线程）间变化,这样可以防止编译器进行优化,确保每次读取时都从内存中获取最新值.
void * volatile low[64];
void * volatile high[64];

void update_range(int T, void * ptr) {
    if (ptr < low[T]) low[T] = ptr;
    if (ptr > high[T]) high[T] = ptr;
}

void probe(int T, int n) {
    update_range(T, &n);
    long sz = (uintptr_t)high[T] - (uintptr_t)low[T];
    if (sz % 1024 < 32) {
        printf("Stack(T%d) >= %ld KB\n", T, sz / 1024);
    }
    probe(T, n+1);
}

void Tprobe(int T) {
    low[T] = (void *)-1;  // (void *)-1 表示一个非常高的内存地址，实际上这个地址是无效的，因为它通常不对应于任何有效的物理内存区域。意味着在未探测到任何有效的栈空间之前，low[T] 会被视为“无效”或“未定义”的状态。这种设计确保了在第一次更新时，任何实际的栈地址都会比这个初始值小，因此能够正确记录最小栈地址。
    high[T] = (void *)0;  //（void *)0 是 C 中代表空指针的常量，它通常指向内存地址的开始（即零地址），将 high[T] 初始化为 (void *)0 意味着在没有探测到任何栈空间之前，high[T] 被视为一个低的基线值。这样，第一次更新时任何有效的栈地址都会比这个值大，从而能够正确记录最大栈地址。
    update_range(T, &T);  // 这一步相当于初始化栈的low和high为&T
    probe(T, 0);          // 不断递归随着栈生长的方向更新low
}

/*  test sum  */
#define N 100000000
long sum = 0;

void Tsum() {
    for (int i = 0; i < N; ++i) {
        sum++;
    }
}
/*  test sum end */


/* test x & y component number */
// int x = 0, y = 0;
// atomic_int flag;
// #define FLAG atomic_load(&flag)
// #define FLAG_XOR(val) atomic_fetch_xor(&flag, val)
// #define WAIT_FOR(cond) while(!(cond));

// __attribute__((noinline))
// void write_x_read_y() {
//     int y_val;
//     asm volatile (
//         "movl $1, %0;" // x = 1
//         "movl %2, %1;" // y_val = y;
//         : "=m"(x), "=r"(y_val) : "m"(y)
//     );
//     printf("%d ", y_val);
// }

/* test x & y component number end */

#define EPSILON 1e-9

#include <math.h>
int main() {
    /// setbuf protobuf: void setbuf(FILE * stream, char * buf);
    /// param: stream: a FILE pointer, such as stdin, stdout, stderr
    /// param: buf: a buffer, if set to NULL, it indicates that no buffer will be used
    /*  test stack size  */
    // setbuf(stdout, NULL);
    // for (int i = 0; i < 4; ++i) {
    //     create(Tprobe);
    // }

    /* test multithread sum */
    create(Tsum);
    create(Tsum);
    join();
    /// 当用O1优化时，结果可能不是200000000
    /// 因为: -O1: R[eax] = sum; R[eax] += N; sum = R[eax]
    /// O2: sum += N
    printf("sum = %ld\n", sum);

    /* test x & y component number  */
    return 0;
}