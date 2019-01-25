#include <stdlib.h>
#include "../stack.c"

struct qs{
    struct stack * s1;
    struct stack * s2;
};

struct qs * create_qs(int size){
    struct qs * n = malloc(sizeof(struct qs));
    n->s1 = create_stack(size);
    n->s2 = create_stack(size);
    return n;
}

int qs_full(struct qs * q){
    return stack_full(q->s1);
}

int qs_empty(struct qs * q){
    return stack_empty(q->s1);
}

int qs_enqueue(struct qs * q, int x){
    return push(q->s1, x);
}

int qs_dequeue(struct qs * q){
    if(!qs_empty(q)){
        while(!stack_empty(q->s1))
            push(q->s2, pop(q->s1));
        int x = pop(q->s2);
        while(!stack_empty(q->s2))
            push(q->s1, pop(q->s2));
        return x;
    }
}

void destroy_qs(struct qs * q){
    destroy_stack(q->s1);
    destroy_stack(q->s2);
    free(q);
}