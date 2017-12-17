//外观模式：为子系统的各个组件提供一个一致的界面，是一个高层接口，使得子系统更加容易使用
////main.cc

#include <iostream>

#include "facade.h"

int main()
{
    ::tyrant::OnlineShoppingFacade facade;
    // 提交订单
    facade.submitRequest();
    // 跟踪订单，直到订单完成
    while (!facade.checkStatus());

    std::cout << "********** 订单完成，跟踪次数：" << facade.followupNum() << " **********" << std::endl;

    return 0;
}
