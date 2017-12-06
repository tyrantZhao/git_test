//main.catch
//将一个一拥有的接口转换为目标借口形式
//适用条件：已有接口和目标接口形式不一致的时候，或者希望复用一个类，但是它和其它类不能协同工作的时候
//注意：适配器模式不已大量出现，必要的时候优先考虑重构
#include "Adapter.h"

int main()
{
    ::tyrant::Adapter Adapt;

    Adapt.Charge();

    return 0;
}
