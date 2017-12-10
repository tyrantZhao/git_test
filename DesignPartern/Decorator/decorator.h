#ifndef __DECORATOR_DECORATOR_H_INCLUDED__
#define __DECORATOR_DECORATOR_H_INCLUDED__

#include "component.h"

namespace tyrant
{
    //抽象装饰器，维护一个抽象构件的指针，并提供一个和抽象构建一致的接口
    class DecoratorInterface
    {
    public:
        DecoratorInterface(ComponentInterface* impl) : impl_(impl) {}
        virtual ~DecoratorInterface() {
            if (impl_)
                impl_ = nullptr;
        };

        virtual ::std::string GetName() = 0;

    protected:
        ComponentInterface* impl_;
    };
} // tyrant

#endif //__DECORATOR_DECORATOR_H_INCLUDED__
