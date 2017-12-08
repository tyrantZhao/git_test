#ifndef __BRIDGE_CONCRETE_H_INCLUDED__
#define __BRIDGE_CONCRETE_H_INCLUDED__

#include <iostream>

#include "abstract.h"
#include "concreteimpl.h"

namespace tyrant
{
    //实现抽象类接口，维护一个代理类指针
    class ConcreteA : public AbstractInterface
    {
    public:
        ConcreteA(AbstractImplInterface* impl) { impl_ = impl; }
        virtual ~ConcreteA () {
            if (impl_)
                impl_ = nullptr;
        }

        virtual void Operation() {
            ::std::cout << "ConcreteA::Operation()" << ::std::endl;
            impl_->Operation();
        }
    private:
        AbstractImplInterface* impl_;
    };

    class ConcreteB : public AbstractInterface
    {
    public:
        ConcreteB(AbstractImplInterface* impl) : impl_(impl) {}
        virtual ~ConcreteB() {
            if (impl_)
                impl_ = nullptr;
        }

        virtual void Operation() {
            ::std::cout << "ConcreteB::Operation()" << ::std::endl;
            impl_->Operation();
        }

    private:
        AbstractImplInterface* impl_;
    };
}

#endif //__BRIDGE_CONCRETE_H_INCLUDED__
