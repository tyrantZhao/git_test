//main.cc
//装饰器模式，动态地给对象添加附加职责，这种方式比继承更为灵活
//适用条件，对象需要动态的添加附加职责，需要复杂的附加职责或多个附加职责组合
#include <iostream>

#include "concretecomponent.h"
#include "concretedecorator.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(ptr) { if (ptr) { delete ptr; ptr = nullptr; } }

int main()
{
    auto pConcreteCompA = new ::tyrant::ConcreteComponentA();
    auto pConcreteCompB = new ::tyrant::ConcreteComponentB();

   ::tyrant::ConcreteDecoratorA oConcreteDecoratorAA(pConcreteCompA);
   ::tyrant::ConcreteDecoratorA oConcreteDecoratorAB(pConcreteCompB);
   ::tyrant::ConcreteDecoratorB oConcreteDecoratorBA(pConcreteCompA);
   ::tyrant::ConcreteDecoratorB oConcreteDecoratorBB(pConcreteCompB);

   ::std::cout << oConcreteDecoratorAA.GetName() << ::std::endl;
   ::std::cout << oConcreteDecoratorAB.GetName() << ::std::endl;
   ::std::cout << oConcreteDecoratorBA.GetName() << ::std::endl;
   ::std::cout << oConcreteDecoratorBB.GetName() << ::std::endl;


    SAFE_DELETE(pConcreteCompA)
    SAFE_DELETE(pConcreteCompB)
    return 0;
}

#endif //SAFE_DELETE
