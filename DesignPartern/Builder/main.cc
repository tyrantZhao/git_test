//此设计模式宗旨：分离复杂产品的创建过程与具体表示，使之可以用于同类型但参数不同的产品的构建
//适用条件：诸多不同的具体产品必须要有相同的性质，只能是参数不同而已
//以联想电脑产品为例，联想旗下有诸多电脑产品，为产品的制造订立一个统一的创建过程，适用于所有的具体的表示

#include <iostream>
#include <memory>

#include "Computer.h"
#include "Builder.h"
#include "Director.h"

int main()
{
    auto TpBuilder = ::std::make_shared<::tyrant::TpBuilder>();
    auto YogaBuilder = ::std::make_shared<::tyrant::YogaBuilder>();

    ::std::unique_ptr<::tyrant::Director> Direct(new ::tyrant::Director());
    Direct->Create(TpBuilder);
    Direct->Create(YogaBuilder);

    ::tyrant::Computer* TpComputer = TpBuilder->GetResult();
    ::tyrant::Computer* YogaComputer = YogaBuilder->GetResult();

    //输出ThingPad 和 Yoga 的信息
    ::std::cout << "ThinkPad Info : " << ::std::endl;
    ::std::cout << " Cpu : " << TpComputer->GetCpu() << ", Mem : " 
        << TpComputer->GetMem() << ", MainBoard : " << TpComputer->GetMainBoard()
        << ", VideoCard : " << TpComputer->GetVideoCard() << ::std::endl;
    ::std::cout << "Yoga Info : " << ::std::endl;
    ::std::cout << "Cpu : " << YogaComputer->GetCpu() << ", Mem : "
        << YogaComputer->GetMem() << ", MainBoard : " << YogaComputer->GetMainBoard()
        << ", VideoCard : " << YogaComputer->GetVideoCard() << ::std::endl;


    return 0;
}

