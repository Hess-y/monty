#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct stack {
    int value;
    struct stack *next;
} stack;

extern stack *head;

extern void push(int value);

extern void pall();

#endif

