#ifndef __COMPOSITE_COMPONENT_H_INCLUDED__
#define __COMPOSITE_COMPONENT_H_INCLUDED__

#include <string>

namespace tyrant
{
    //抽象构件
    class Component
    {
    public:
        Component(::std::string sName) : sName_(sName) {}
        virtual ~Component() {}

        virtual void Operation(int nIedent) = 0;
    protected:
        ::std::string sName_;
    };
} //tyrant

#endif //__COMPOSITE_COMPONENT_H_INCLUDED__
