#ifndef __ABSTRACTFACTORY_ABFACTORY_H_
#define __ABSTRACTFACTORY_ABFACTORY_H_

#include "ConcreteProduct.h"

namespace tyrant
{
    //抽象工厂，用于提供创造抽象产品的接口，同时提供创造具体工厂的接口和类型
    class AbFactory
    {
        public:
            AbFactory() = default;
            virtual ~AbFactory() = default;

        //工厂种类
        enum FACTORY_TYPE {
            BENZ_FACTORY,  // 奔驰工厂
            AUDI_FACTORY  // 奥迪工厂
        };

        virtual CarInterface* CreateCar() = 0;  // 生产汽车
        virtual BycircleInterface* CreateBycircle() = 0;    // 生产自行车
        static AbFactory* CreateFactory(FACTORY_TYPE factory);  // 创建工厂
    };
}

#endif //__ABSTRACTFACTORY_ABFACTORY_H_
