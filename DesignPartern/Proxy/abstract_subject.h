#ifndef __PROXY_ABSTRACT_SUBJECT_H__
#define __PROXY_ABSTRACT_SUBJECT_H__

namespace tyrant
{
    //提供抽象主题，定义了真实主题和代理共同拥有的接口
    class SubjectInterface
    {
    public:
        SubjectInterface() = default;
        virtual ~SubjectInterface() = default;

    public:
        virtual void  rechargeMoney(int nMoney) = 0;
    };
} //tyrant

#endif //abstract_subject.h
