#ifndef __FACKTORY_ABSTRACT_H__
#define __FACKTORY_ABSTRACT_H__

#include <memory>

#include "AbstractProduct.h"

namespace tyrant
{
    //抽象工厂，提供一个创建产品的接口，所有的工厂类实现都要实现该接口
    class FactoryInterface
    {
        public:
            virtual ::std::shared_ptr<CarInterface> CreateCar() = 0;
    };
}

#endif //vmlinuz__FACKTORY_ABSTRACT_H__
