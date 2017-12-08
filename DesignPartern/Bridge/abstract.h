#ifndef __BRIDGE_ABSTRACT_H_INCLUDED__
#define __BRIDGE_ABSTRACT_H_INCLUDED__

namespace tyrant
{
    //抽象类，提供操作的抽象接口
    class AbstractInterface
    {
    public:
        virtual ~AbstractInterface() = default;

        virtual void Operation() = 0;

    protected:
        AbstractInterface() = default;
    };
}

#endif //__BRIDGE_ABSTRACT_H_INCLUDED__
