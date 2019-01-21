#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct stack {
    int top;
    int size;
    int * arrange;
};

struct stack * create_stack(int size){
    struct stack * s = malloc(sizeof(struct stack));
    s->arrange = malloc(sizeof(int)*size);
    s->size = size;
    s->top = -1;
    return s;
}

int stack_empty(struct stack * s){
    return s->top == -1;
}

void push(struct stack * s, int x){
    if(s->top < s->size-1){
        s->top++;
        s->arrange[s->top] = x;
    }
    else{
        printf("stack overflow\n");
    }
}

int pop(struct stack * s){
    if(!stack_empty(s)){
        int x = s->arrange[s->top];
        s->top--;
        return x;
    }
    else{
        printf("stack empty\n");
        return INT_MIN;
    }
}

void destroy_stack(struct stack * s){
    free(s->arrange);
    free(s);
}