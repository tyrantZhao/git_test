#ifndef  __ADAPTER_ADAPTEE_H__INCLUDED__
#define __ADAPTER_ADAPTEE_H__INCLUDED__

#include <iostream>

namespace tyrant
{
    //提供待转换借口
    class Adaptee
    {
    public:
        Adaptee() = default;
        ~Adaptee() = default;

        void ChargeFlat() {
            ::std::cout << "Owner: Charge myself!" << ::std::endl;
        }
    };
}

#endif //__ADAPTER_ADAPTEE_H__INCLUDED__
