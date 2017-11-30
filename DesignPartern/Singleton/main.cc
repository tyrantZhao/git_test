//test for singleton partern
//this partern means one class must have one instance, and just like global variable, but more lazier
#include "singleton.h"

int main()
{
    //correctly run
    ::tyrant::Singleton::getInstance().DoSomeThing();

    //occur compile error
    // ::TyrantZhao::Singleton Inst;
    // Inst.DoSomeThing();

    return 0;
}


