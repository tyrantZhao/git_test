#include <iostream>
#include <memory>

#include "ConcreteProduct.h"
#include "ConcreteFactory.h"

int main()
{
    auto BenzFact = ::std::make_shared<::tyrant::BenzFactory>();
    auto BenzCar = BenzFact->CreateCar();
    ::std::cout << "BenzCarFactory : " << BenzCar->GetName() << ::std::endl;

    auto AudiFact = ::std::make_shared<::tyrant::AudiFactory>();
    auto AudiCar  = AudiFact->CreateCar();
    ::std::cout << "AudiCarFactory : " << AudiCar->GetName() << ::std::endl;

    return 0;
}
