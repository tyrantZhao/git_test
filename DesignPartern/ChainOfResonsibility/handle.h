#ifndef __COR_HANDLER_H__
#define __COR_HANDLER_H__

namespace tyrant
{
    //抽象节点， 规范请求所需处理函数接口
    class HandleInterface
    {
    public:
        HandleInterface() = default;
        virtual ~HandleInterface() = default;

    public:
        //请求处理接口
        virtual void handleRequest(float fDay) = 0;
        //设置相邻处理节点
        virtual void setHandle(HandleInterface* pHandle) {}
    };
} //tyrant

#endif //handle.h
