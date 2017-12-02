#include <iostream>

#include "AbstractFactory.h"
#include "ConcreteFactory.h"

namespace tyrant
{
    AbFactory* AbFactory::CreateFactory(FACTORY_TYPE factory)
    {
        AbFactory* fact = NULL;
        switch(factory) {
            case FACTORY_TYPE::BENZ_FACTORY:
                {
                    fact = new BenzFactory();
                }
                break;
            case FACTORY_TYPE::AUDI_FACTORY:
                {
                    fact = new AudiFactory();
                }
                break;
            default:
                ::std::cout << "invalid factory type " << ::std::endl;
        }

        return fact;
    }
}
