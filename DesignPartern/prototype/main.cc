//用原型实例来指定对象种类，复制这个实例来制造新的对象，无需理会创建过程，获取对象状态
//适用条件：对象较为复杂，创建对象开销大，对象占用内存较小
#include <iostream>
#include <string>
#include <memory>

#include "concreteprototype.h"

int main()
{
    auto RobotKing1 = ::std::make_shared<::tyrant::RobotKing>("king1");
    //复制得到的新的对象
    auto RobotKing2 = RobotKing1->Clone();
    auto RobotKing3 = RobotKing1->Clone();
    auto RobotKing4 = RobotKing1->Clone();

    RobotKing2->Attack();
    RobotKing3->Attack();
    RobotKing4->Attack();

    return 0;
}
