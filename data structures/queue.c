#include <stdlib.h>
#include <limits.h>
#define QUEUE_EMPTY INT_MIN
#define QUEUE_FULL 0

struct queue{
    int size;
    int head;
    int tail;
    int length;
    int * arrange;
};

struct queue * create_queue(int size){
    struct queue * q = malloc(sizeof(struct queue));
    q->arrange = malloc(sizeof(int) * size);
    q->head = q->tail = 0;
    q->size = size;
    q->length = 0;
    return q;
}

int empty_queue(struct queue * q){
    return q->length == 0;
}

int full_queue(struct queue * q){
    return q->length == q->size;
}

int enqueue(struct queue * q, int x){
    if(!full_queue(q)){
        q->arrange[q->tail] = x;
        q->length++;
        if(q->tail == q->size-1)
            q->tail = 0;
        else
            q->tail++;
        return 1;
    }
    else
        return QUEUE_FULL;
}

int dequeue(struct queue * q){
    if(!empty_queue(q)){
        int x = q->arrange[q->head];
        q->length--;
        if(q->head == q->size-1)
            q->head = 0;
        else
            q->head++;
        return x;
    }
    else{
        return QUEUE_EMPTY;
    }
}

void destroy_queue(struct queue * q){
    free(q->arrange);
    free(q);
}