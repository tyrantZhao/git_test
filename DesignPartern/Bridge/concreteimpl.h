#ifndef __BRIDGE_CONCRETEIMPL_H_INCLUDED__
#define __BRIDGE_CONCRETEIMPL_H_INCLUDED__

#include <iostream>

#include "abstractimpl.h"

namespace tyrant
{
    //实现代理类的操作接口
    class ConcreteImplA : public AbstractImplInterface
    {
    public:
        ConcreteImplA() = default;
        virtual ~ConcreteImplA() = default;

        virtual void Operation() { ::std::cout << "ConcreteImplA::Operation()" << ::std::endl; }
    };

    class ConcreteImplB : public AbstractImplInterface
    {
    public:
        ConcreteImplB() = default;
        virtual ~ConcreteImplB() = default;

        virtual void Operation() { ::std::cout << "ConcreteImplB::Operation()" << ::std::endl; }
    };
}

#endif //__BRIDGE_CONCRETEIMPL_H_INCLUDED__
