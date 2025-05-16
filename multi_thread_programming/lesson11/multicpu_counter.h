#ifndef MULTICPU_COUNTER_H_
#define MULTICPU_COUNTER_H_

#include <pthread.h>

constexpr int NUMCPUS = 4;

typedef struct __counter_t {
    int global;                // global count;
    pthread_mutex_t glock;    // global lock
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
    if (c->local[cpu] > c->threadshold) {
        pthread_mutex_lock(&c->glock);
        c->global += c->local[cpu];
        pthread_mutex_unlock(&c->glock);
        c->local[cpu] = 0;
    }
    pthread_mutex_unlock(&c->llock[cpu]);
}

int get(counter_t * c) {
    pthread_mutex_lock(&c->glock);
    int val = c->global;
    pthread_mutex_unlock(&c->glock);
    return val;
}

#endif