//main.cc
//代理模式：为其他对象提供一个代理，控制这个对象的访问
//适用场景：不希望直接引用这个对象，或者希望添加一些额外的动作，或者希望引入缓存机制

#include "proxy.h"

int main()
{
    tyrant::Proxy oProxy;

    oProxy.rechargeMoney(20);
    oProxy.rechargeMoney(100);

    return 0;
}
