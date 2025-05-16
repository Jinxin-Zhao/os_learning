#ifndef _LAB_ELEVEN_H_
#define _LAB_ELEVEN_H_

#include <unistd.h>
#include <pthread.h>

////////////////////////////// lock based structure //////////////////////////////
// the lock based counter
// typedef struct __counter_t {
//     int value;
//     pthread_mutex_t lock;
// } counter_t;

// void init(counter_t * c) {
//     c->value = 0;
//     pthread_mutex_init(&c->lock, NULL);
// }

// void increment(counter_t * c) {
//     pthread_mutex_lock(&c->lock);
//     c->value++;
//     pthread_mutex_unlock(&c->lock);
// }

// void decrement(counter_t * c) {
//     pthread_mutex_lock(&c->lock);
//     c->value--;
//     pthread_mutex_unlock(&c->lock);
// }

// int get(counter_t * c) {
//     pthread_mutex_lock(&c->lock);
//     int rc = c->value;
//     pthread_mutex_unlock(&c->lock);
//     return rc;
// }

////////////////// [4 CPUs & a global counter] version ///////////////////////
#define NUMCPUS 4
typedef struct __counter_t {
    int global;
    pthread_mutex_t glock;
    int local[NUMCPUS];
    pthread_mutex_t llock[NUMCPUS];
    int threadshold;
} counter_t;

void init(counter_t * c, int threshold) {
    c->threadshold = threshold;
    c->global = 0;
    pthread_mutex_init(&c->glock, NULL);
    for (int i = 0; i < NUMCPUS; ++i) {
        c->local[i] = 0;
        pthread_mutex_init(&c->llock[i], NULL);
    }
}

void update(counter_t * c, int threadID, int amt) {
    int cpu = threadID % NUMCPUS;
    pthread_mutex_lock(&c->llock[cpu]);
    c->local[cpu] += amt;
    if (c->local[cpu] >= c->threadshold) {
        pthread_mutex_lock(&c->glock);
        c->global += c->local[cpu];
        pthread_mutex_unlock(&c->glock);
        c->local[cpu] = 0;
    }
    pthread_mutex_unlock(&c->llock[cpu]);
}

int get(counter_t * c) {
    pthread_mutex_lock(&c->glock);
    int rc = c->global;
    pthread_mutex_unlock(&c->glock);
    return rc;
}

int getCPUNumbers() {
    return sysconf(_SC_NPROCESSORS_CONF);
}

//////////////////////////// lock based structure //////////////////////////////




#endif