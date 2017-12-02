#ifndef __ABSTRACTFACTROY_CONCRETEFACTORY_H__
#define __ABSTRACTFACTROY_CONCRETEFACTORY_H__

#include "AbstractFactory.h"
#include "ConcreteProduct.h"

namespace tyrant
{
    //具体工厂， 创造具体的产品
    class BenzFactory : public AbFactory
    {
        public:
            BenzFactory() = default;
            virtual ~BenzFactory() = default;

            virtual CarInterface* CreateCar() { return new BenzCar(); }
            virtual BycircleInterface* CreateBycircle() { return new BenzBycircle(); }
    };

    class AudiFactory : public AbFactory
    {
        public:
            AudiFactory() = default;
            virtual ~AudiFactory() = default;

            virtual CarInterface* CreateCar() { return new AudiCar(); }
            virtual BycircleInterface* CreateBycircle() { return new AudiBycircle(); }
    };
}

#endif //__ABSTRACTFACTROY_CONCRETEFACTORY_H__
