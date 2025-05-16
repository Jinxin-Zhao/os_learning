#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <assert.h>

#define NTHREAD 64
enum {T_FREE = 0, T_LIVE, T_DEAD, };
struct thread {
    int id;
    int status;
    pthread_t thread;
    void (*entry)(int);
};

struct thread tpool[NTHREAD];
struct thread * tptr = tpool;

void * wrapper(void * arg) {
    struct thread * thread = (struct thread *)arg;
    thread->entry(thread->id);
    return NULL;
}

void create(void * fn) {
    assert(tptr - tpool < NTHREAD);
    *tptr = (struct thread) {
        .id = tptr - tpool + 1,
        .status = T_LIVE,
        .entry = fn,
    };
    pthread_create(&(tptr->thread), NULL, wrapper, tptr);
    ++tptr;
}

void join(){
    for (int i = 0; i < NTHREAD; i++) {
        struct thread * t = &tpool[i];
        if (t->status == T_LIVE) {
            pthread_join(t->thread, NULL);
            t->status = T_DEAD;
        }
    }
}


// __attribute__((destructor)):
// 这是一个特殊的属性，指示编译器该函数是一个析构函数。当程序正常终止时（例如，通过 main 函数的返回或调用 exit 函数），这个函数将被自动调用。
// 可以有多个析构函数，它们的执行顺序是与它们的定义顺序相反的。
__attribute__ ((destructor)) void cleanup() {
    join();
}