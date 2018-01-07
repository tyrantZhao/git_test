#ifndef __PROXY_REAL_SUBJECT_H__
#define __PROXY_REAL_SUBJECT_H__

#include <iostream>

#include "abstract_subject.h"

namespace tyrant
{
    //真实的对象，用于处理业务逻辑
    class CmccInc : public SubjectInterface
    {
    public:
        CmccInc() = default;
        virtual ~CmccInc() = default;

    public:
        void rechargeMoney(int nMoney) override
        {
            ::std::cout << "you have recharged : " << nMoney << ::std::endl;
        }
    };
} //tyrant

#endif //real_subject.h
