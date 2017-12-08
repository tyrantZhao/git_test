#ifndef __BRIDGE_ABSTRACTIMPL_H_INCLUDED__
#define __BRIDGE_ABSTRACTIMPL_H_INCLUDED__

namespace tyrant
{
    //提供了被抽象类操作的外部操作接口
    class AbstractImplInterface
    {
    public:
        virtual ~AbstractImplInterface() = default;

        virtual void Operation() = 0;

    protected:
        AbstractImplInterface() = default;
    };
}

#endif //__BRIDGE_ABSTRACTIMPL_H_INCLUDED__
