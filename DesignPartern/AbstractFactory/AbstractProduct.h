#ifndef __ABSTRACTFACTORY_ABSTRACTPRODUCT_H_
#define __ABSTRACTFACTORY_ABSTRACTPRODUCT_H_

#include <string>

namespace tyrant
{
    //抽象产品， 以汽车和自行车为例
    class CarInterface
    {
        public:
            CarInterface() = default;
            virtual ~CarInterface() = default;

            virtual ::std::string GetName() = 0;
    };

    class BycircleInterface
    {
        public:
            BycircleInterface() = default;
            virtual ~BycircleInterface() = default;

            virtual ::std::string GetName() = 0;
    };
}

#endif //__ABSTRACTFACTORY_ABSTRACTPRODUCT_H_
