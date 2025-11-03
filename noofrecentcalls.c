#include <stdlib.h>

typedef struct {
    int* requests;
    int head;
    int tail;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));
    obj->requests = (int*)malloc(10001 * sizeof(int));
    obj->head = 0;
    obj->tail = 0;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->requests[obj->tail++] = t;
    while (obj->requests[obj->head] < t - 3000) {
        obj->head++;
    }
    return obj->tail - obj->head;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->requests);
    free(obj);
}