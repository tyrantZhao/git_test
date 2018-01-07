#include "stack.h"

#include <iostream>

stack assist;

bool empty(stack* st)
{
    if (nullptr == st)
        std::cout << "stack is not exists" << std::endl;
        return true;

    if (st->top == -1)
        return true;

    return false;
}

bool full(stack* st)
{
    if (nullptr == st)
        std::cout << "stack is not exists" << std::endl;
        return false;

    if (stack_size == st->top + 1)
        return true;

    return false;
}

void push(stack* st, int value)
{
   if (full(st)) {
       std::cout << "push : stack is full" << std::endl;
       return;
   }

   if (-1 == st->min || value < st->min) {
        st->min = value;
        assist.data[++assist.top] = value;
   }

   st->data[++st->top] = value;
}

int  pop(stack* st)
{
    if (!empty(st)) {
        std::cout << "pop : stack is empty" << std::endl;
        return -1;
    }

    int data = st->data[st->top--];
    if (data == assist.data[assist.top]) {
        st->min = assist.data[assist.top--];
    }

    return data;
}

int min(stack* st)
{
    if (nullptr == st)
        return -1;

    return st->min;
}
