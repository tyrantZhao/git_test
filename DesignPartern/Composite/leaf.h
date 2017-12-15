#ifndef __COMPOSITE_LEAF_H_INCLUDED__
#define __COMPOSITE_LEAF_H_INCLUDED__

#include <iostream>
#include "component.h"

namespace tyrant
{
    //叶子结点
    class Leaf : public Component
    {
    public:
        Leaf(::std::string sName) : Component(sName) {}
        virtual ~Leaf() = default;

        virtual void Operation(int nIndent) override {
            ::std::string sIn(nIndent, '-');
            ::std::cout << "sIn" << sIn << ", sName_ : " << sName_ << ::std::endl;
        }
    };
} //tyrant

#endif //__COMPOSITE_LEAF_H_INCLUDED__
