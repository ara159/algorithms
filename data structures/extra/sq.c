#include <stdlib.h>
#include "../queue.c"

struct sq {
    struct queue * q1;
    struct queue * q2;
};

struct sq * create_sq(int size){
    struct sq * n = malloc(sizeof(struct sq));
    n->q1 = create_queue(size);
    n->q2 = create_queue(size);
    return n;
}

int sq_empty(struct sq * s){
    return empty_queue(s->q1);
}

int sq_full(struct sq * s){
    return full_queue(s->q1);
}

int sq_push(struct sq * s, int x){
    return enqueue(s->q1, x);
}

int sq_pop(struct sq * s){
    int x;
    while(1){
        x = dequeue(s->q1);
        if(empty_queue(s->q1))
            break;
        else
            enqueue(s->q2, x);
    }
    while(!empty_queue(s->q2))
        enqueue(s->q1, dequeue(s->q2));
    return x;
}

void sq_destroy(struct sq * s){
    destroy_queue(s->q1);
    destroy_queue(s->q2);
    free(s);
}