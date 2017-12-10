#ifndef __DECORATOR_CONCRETEDEDECORATOR_H_INCLUDED__
#define __DECORATOR_CONCRETEDEDECORATOR_H_INCLUDED__

#include "decorator.h"

namespace tyrant
{
    //具体装饰器，给具体构件添加附加职责
    class ConcreteDecoratorA : public DecoratorInterface
    {
    public:
        ConcreteDecoratorA(ComponentInterface* impl) : DecoratorInterface(impl) {}
        virtual ~ConcreteDecoratorA() {}

        virtual ::std::string GetName() {
            return impl_->GetName() + " + ConcreteDecoratorA";
        }
    };

    class ConcreteDecoratorB : public DecoratorInterface
    {
    public:
        ConcreteDecoratorB(ComponentInterface* impl) : DecoratorInterface(impl) {}
        virtual ~ConcreteDecoratorB() {};

        virtual ::std::string GetName() {
            return impl_->GetName() + " + ConcreteDecoratorB";
        }

    };
} //tyrant

#endif //__DECORATOR_CONCRETEDEDECORATOR_H_INCLUDED__
