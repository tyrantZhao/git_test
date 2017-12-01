#ifndef __FACTORYMETHOD_CONCRETEPRODUCT_H__
#define __FACTORYMETHOD_CONCRETEPRODUCT_H__

#include <string>

#include "AbstractProduct.h"

namespace tyrant
{
    //具体产品表示
    class Benz : public CarInterface
    {
        public:
            Benz() { name_ = " Benz Car "; }
            virtual ~Benz() = default;

            virtual ::std::string GetName() { return name_; }

        private:
            ::std::string name_;

    };

    class Audi : public CarInterface
    {
        public:
            Audi() { name_ = "Audi"; }
            virtual ~Audi() = default;


            ::std::string GetName() { return name_; }
        private:
            ::std::string name_;

    };
}

#endif //__FACTORYMETHOD_CONCRETEPRODUCT_H__
