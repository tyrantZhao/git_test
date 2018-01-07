#ifndef __PROXY_PROXY_H__
#define __PROXY_PROXY_H__

#include <iostream>

#include "abstract_subject.h"
#include "real_subject.h"

namespace tyrant
{
    //代理对象, 持有一个真实主题的指针，可以添加一些额外的功能，类似与装时器模式
    class Proxy : SubjectInterface
    {
    public:
        Proxy()
        {
            Cmcc_ = new CmccInc();
        }
        virtual ~Proxy()
        {
            if (nullptr != Cmcc_) {
                delete Cmcc_;
                Cmcc_ = nullptr;
            }
        };

    public:
        virtual void rechargeMoney(int nMoney) override
        {
            if (20 >= nMoney) {
                ::std::cout << "your money rechared is too few!" << ::std::endl;
            }

            if (100 <= nMoney) {
                Cmcc_->rechargeMoney(nMoney);
                ::std::cout << "Rechared successful!" << ::std::endl;
            }
        }

    private:
        CmccInc* Cmcc_;
    };
} //tyrant

#endif //proxy.h
