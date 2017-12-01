#ifndef __PROTOTYPE__CONCRETE_H_
#define __PROTOTYPE__CONCRETE_H_

#include <iostream>
#include <string>

#include "prototype.h"

namespace tyrant
{
    //实现基类的clone接口，复制对象的状态
    class RobotKing : public Robot
    {
        public:
            RobotKing(::std::string name) { name_ = name; }
            virtual ~RobotKing() = default;

            virtual ::std::shared_ptr<Robot> Clone() { return ::std::static_pointer_cast<Robot>(::std::make_shared<RobotKing>(name_)); }
            virtual void Attack() { ::std::cout << "I'm " << name_ <<" attcking~~~" << ::std::endl; }
        private:
            ::std::string name_;
    };
}

#endif //__PROTOTYPE__CONCRETE_H_
