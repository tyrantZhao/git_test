#ifndef __FACTORYMETHOD_CONCRETEFACTORY_H__
#define __FACTORYMETHOD_CONCRETEFACTORY_H__

#include <iostream>
#include <string>
#include <memory>

#include "AbstractFactry.h"
#include "ConcreteProduct.h"

namespace tyrant
{
    class BenzFactory : public FactoryInterface
    {
        public:
            BenzFactory() = default;
            virtual ~BenzFactory() = default;

            ::std::shared_ptr<CarInterface> CreateCar() {
                return ::std::static_pointer_cast<CarInterface>(::std::make_shared<Benz>());
            }
    };
    class AudiFactory : public FactoryInterface
    {
        public:
            AudiFactory() = default;
            virtual ~AudiFactory() = default;

            ::std::shared_ptr<CarInterface> CreateCar() {
                return ::std::static_pointer_cast<CarInterface>(::std::make_shared<Audi>());
            }
    };
}

#endif //__FACTORYMETHOD_CONCRETEFACTORY_H__
