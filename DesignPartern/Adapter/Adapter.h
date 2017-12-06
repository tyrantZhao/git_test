#ifndef __ADAPTER_ADAPTER_H_INCLUDED__
#define __ADAPTER_ADAPTER_H_INCLUDED__

#include <memory>

#include "Target.h"
#include "Adaptee.h"

namespace tyrant
{
    //适配器，提供转换
    class Adapter : public RussiaSocketInterface
    {
    public:
        Adapter() : Charger_(new Adaptee()) {}
        virtual ~Adapter() {}

        virtual void Charge() { Charger_->ChargeFlat(); }

    private:
        ::std::unique_ptr<Adaptee> Charger_;
    };
}

#endif //__ADAPTER_ADAPTER_H_INCLUDED__
