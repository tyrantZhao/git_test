//桥接模式：分离抽象实现和具体实现，使两者可以独立的变化
//适用条件：一个类受多个外部因素影响，或者一个或者多个因素在多个类中间共享
//main.cc

#include <memory>

#include "concrete.h"
#include "concreteimpl.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(ptr) { if(ptr) { delete ptr; ptr = NULL; } }

using namespace tyrant;

int main()
{
    auto ConcreteImplA_p = new ConcreteImplA();
    auto ConcreteImplB_p = new ConcreteImplB();

    ConcreteA ConcreteAImplA(ConcreteImplA_p);
    ConcreteAImplA.Operation();

    ConcreteA ConcreteAImplB(ConcreteImplB_p);
    ConcreteAImplB.Operation();

    ConcreteB ConcreteBImplA(ConcreteImplA_p);
    ConcreteBImplA.Operation();

    ConcreteB ConcreteBImplB(ConcreteImplB_p);
    ConcreteBImplB.Operation();

    SAFE_DELETE(ConcreteImplA_p)
    SAFE_DELETE(ConcreteImplB_p)
}

#endif //SAFE_DELETE
