//main.cc
//使用辅助栈，使得stack的min时间效率为O(1)
#include "stack.h"

#include <iostream>

int main()
{
    stack st;

    push(&st, 3);
    std::cout << "min(）： " << min(&st) << std::endl;

    push(&st, 6);
    std::cout << "min(）： " << min(&st) << std::endl;
    push(&st, 4);
    std::cout << "min(）： " << min(&st) << std::endl;
    push(&st, 2);
    std::cout << "min(）： " << min(&st) << std::endl;
    push(&st, 1);
    std::cout << "min(）： " << min(&st) << std::endl;

    pop(&st);
    std::cout << "min(）： " << min(&st) << std::endl;
    pop(&st);
    std::cout << "min(）： " << min(&st) << std::endl;
    pop(&st);
    std::cout << "min(）： " << min(&st) << std::endl;

    return 0;
}
