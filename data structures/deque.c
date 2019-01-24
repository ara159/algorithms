#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define QUEUE_FULL 0
#define QUEUE_EMPTY INT_MIN

struct deque {
    int head;
    int tail;
    int size;
    int length;
    int * arrange;
};

struct deque * create_deque(int size){
    struct deque * q = malloc(sizeof(struct deque));
    q->arrange = malloc(sizeof(int) * size);
    q->head = q->tail = 0;
    q->size = size;
    q->length = 0;
    return q;
}

int deque_empty(struct deque * d){
    return d->length == 0;
}

int deque_full(struct deque * d){
    return d->length == d->size;
}

void deque_print(struct deque * d){
    printf("deque: ");
    for(int i = 0; i < d->size; i++)
        printf("%d, ", d->arrange[i]);
    printf("\n");
}

int deque_insert_first(struct deque * d, int x){
    if(!deque_full(d)){
        if(d->head-1 < 0)
            d->head = d->size-1;
        else
            d->head--;
        d->arrange[d->head] = x;
        d->length++;
        return 1;
    }
    else
        return QUEUE_FULL;
}

int deque_insert_last(struct deque * d, int x){
    if(!deque_full(d)){
        d->arrange[d->tail] = x;
        if(d->tail == d->size-1)
            d->tail = 0;
        else
            d->tail++;
        d->length++;
        return 1;
    }
    else
        return QUEUE_FULL;
}

int deque_remove_first(struct deque * d){
    if(!deque_empty(d)){
        int x = d->arrange[d->head];
        d->arrange[d->head] = -1;
        if(d->head == d->size-1)
            d->head = 0;
        else
            d->head++;
        d->length--;
        return x;
    }
    else
        return QUEUE_EMPTY;
}

int deque_remove_last(struct deque * d){
    if(!deque_empty(d)){
        if(d->tail == 0)
            d->tail = d->size-1;
        else
            d->tail--;
        int x = d->arrange[d->tail];
        d->arrange[d->tail] = -1;
        d->length--;
        return x;
    }
    else
        return QUEUE_EMPTY;
}

void deque_destroy(struct deque * d){
    free(d->arrange);
    free(d);
}