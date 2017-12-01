#ifndef __PROTOTYPE_PROTOTYPE_H__
#define __PROTOTYPE_PROTOTYPE_H__

#include <memory>

namespace tyrant
{
    //抽象原型，提供一个复制自身的接口
    class Robot
    {
        public:
            Robot() = default;
            virtual ~Robot() = default;


            //复制自身
            virtual  ::std::shared_ptr<Robot> Clone() = 0;
            //执行动作
            virtual void Attack() = 0;
    };
}
#endif //__PROTOTYPE_PROTOTYPE_H__
