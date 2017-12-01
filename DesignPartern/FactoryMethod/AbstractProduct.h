#ifndef __FACTORYMETHOD_ABSTRACTPRODUCT_H__
#define __FACTORYMETHOD_ABSTRACTPRODUCT_H__

#include <string>

namespace tyrant
{
    //抽象产品类， 提供一个产品接口
    class CarInterface
    {
        public:
            virtual ::std::string GetName() = 0;
    };
}

#endif //__FACTORYMETHOD_ABSTRACTPRODUCT_H__
