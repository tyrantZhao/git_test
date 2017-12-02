// main.cpp
//抽象工厂模式：指定了一系列相关或者相互依赖的产品的接口，无需关心子类的实现
//拓宽了产品的类别，一个工厂可以对应多个产品，但是，每个产品族都要有相同的特点，要修改，需要对所有产品都同意话处理
#include <iostream>

#include "AbstractFactory.h"
#include "ConcreteProduct.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

int main()
{
    // 奔驰
    auto fact = ::tyrant::AbFactory::CreateFactory(::tyrant::AbFactory::FACTORY_TYPE::BENZ_FACTORY);
    auto car = fact->CreateCar();
    auto bycircle = fact->CreateBycircle();

    ::std::cout << "Benz factory - Car: " << car->GetName() << ::std::endl;
    ::std::cout << "Benz factory - Bike: " << bycircle->GetName() << ::std::endl;

    SAFE_DELETE(car);
    SAFE_DELETE(bycircle);
    SAFE_DELETE(fact);


    // 奥迪
    fact = ::tyrant::AbFactory::CreateFactory(::tyrant::AbFactory::FACTORY_TYPE::AUDI_FACTORY);
    car = fact->CreateCar();
    bycircle = fact->CreateBycircle();
    ::std::cout << "Audi factory - Car: " << car->GetName() << ::std::endl;
    ::std::cout << "Audi factory - Bike: " << bycircle->GetName() << ::std::endl;

    SAFE_DELETE(car);
    SAFE_DELETE(bycircle);
    SAFE_DELETE(fact);

    return 0;
}
