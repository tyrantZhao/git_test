#ifndef __DECORATOR_COMPONENT_H_INCLUDED__
#define __DECORATOR_COMPONENT_H_INCLUDED__

#include <string>

namespace tyrant
{
    //抽象构件，提供一个接口，规范准备接收附加责任的类的接口
    class ComponentInterface
    {
    public:
        ComponentInterface() = default;
        virtual ~ComponentInterface() = default;

        //抽象接口
        virtual ::std::string GetName() = 0;
    };
} // tyrant

#endif //__DECORATOR_COMPONENT_H_INCLUDED__
