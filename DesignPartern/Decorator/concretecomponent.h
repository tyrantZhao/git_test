#ifndef __DECORATOR_CONCRETECOMPONENT_H_INCLUDED__
#define __DECORATOR_CONCRETECOMPONENT_H_INCLUDED__

#include "component.h"

namespace tyrant
{
    //具体构件，实现抽象构件的接口
    class ConcreteComponentA : public ComponentInterface
    {
    public:
        ConcreteComponentA() = default;
        virtual ~ConcreteComponentA() = default;

        virtual ::std::string GetName() { return "ConcreteComponentA "; }
    };

    class ConcreteComponentB : public ComponentInterface
    {
    public:
        ConcreteComponentB() = default;
        virtual ~ConcreteComponentB() = default;

        virtual ::std::string GetName() { return "ConcreteComponentB"; }
    };
} //tyrant

#endif //__DECORATOR_CONCRETECOMPONENT_H_INCLUDED__
