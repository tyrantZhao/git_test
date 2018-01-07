#ifndef __STACK_H__
#define __STACK_H__

#include <cstring>

//栈容量
const int stack_size = 20;

#ifdef __cplusplus
extern "C" {
#endif

struct stack
{
    int data[stack_size]; //栈
    int top; //栈顶位置
    int min; //最小元素位置

    stack() : top(-1), min(-1) { memset(&data, 0, sizeof(data)); }
    ~stack() = default;
};

bool empty(stack* st);
bool full(stack* st);
void push(stack* st, int value);
int  pop(stack* st);
int  min(stack* st);

#ifdef __cplusplus
}
#endif

#endif // stack.h
