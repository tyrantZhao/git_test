#ifndef __ABSTRACTFACTROY_CONCRETEPRODUCT_H__
#define __ABSTRACTFACTROY_CONCRETEPRODUCT_H__

#include "AbstractProduct.h"

namespace tyrant
{
    //具体产品，实现抽象产品接口
    class BenzCar : public CarInterface
    {
        public:
            BenzCar() = default;
            virtual ~BenzCar() = default;

            virtual ::std::string GetName() { return "Benz Car" ; }
    };

    class AudiCar : public CarInterface
    {
        public:
            AudiCar() = default;
            virtual ~AudiCar() = default;

            virtual ::std::string GetName() { return "Audi Car" ; }
    };

    class BenzBycircle : public BycircleInterface
    {
        public:
            BenzBycircle() = default;
            virtual ~BenzBycircle() = default;

            virtual ::std::string GetName() { return "Benz Bycircle" ; }
    };
    class AudiBycircle : public BycircleInterface
    {
        public:
            AudiBycircle() = default;
            virtual ~AudiBycircle() = default;

            virtual ::std::string GetName() { return "Audi Bycircle" ; }
    };
}

#endif //__ABSTRACTFACTROY_CONCRETEPRODUCT_H__
