#ifndef __ADAPTER_TARGET_H_INCLUDED__
#define __ADAPTER_TARGET_H_INCLUDED__

namespace tyrant
{
    //提供目标接口
    class RussiaSocketInterface
    {
    public:
        RussiaSocketInterface() = default;
        virtual ~RussiaSocketInterface() = default;

        virtual void Charge() = 0;
    };
}

#endif //__ADAPTER_TARGET_H_INCLUDED__
