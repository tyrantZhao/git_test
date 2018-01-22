#ifndef __COR_HANDLEIMPL_H__
#define __COR_HANDLEIMPL_H__

#include <iostream>

#include "handle.h"

namespace tyrant
{
    //实现基类的请求处理函数，如果请求自己处理不了，则转给相邻的处理节点
    class Manager : public HandleInterface
    {
    public:
        Manager() : pHandle_(nullptr) {};
        virtual ~Manager() {
            setHandle(nullptr);
        };

    public:
        void handleRequest(float fDay) override {
            if (0 > fDay)
                return;

            if (1 >= fDay) {
                std::cout << "Manager allow " << fDay << "'s days leave!" << std::endl;
                return;
            }

            if (pHandle_)
                pHandle_->handleRequest(fDay);
        }

        void setHandle(HandleInterface* pHandle) override {
            if (pHandle_)
                delete pHandle_;

            pHandle_ = pHandle;
        }

    private:
        HandleInterface* pHandle_;
    };

    class Director : public HandleInterface
    {
    public:
        Director() : pHandle_(nullptr) {}
        virtual ~Director() {
            setHandle(nullptr);
        }

    public:
        void handleRequest(float fDay) override {
            if (3 >= fDay) {
                std::cout << "Director allowed " << fDay << "'s days leave" << std::endl;
                return;
            }

            if (pHandle_)
                pHandle_->handleRequest(fDay);
        }

        void setHandle(HandleInterface* pHandle) override {
            if (pHandle_)
                delete pHandle_;

            pHandle_ = pHandle;
        }

    private:
        HandleInterface* pHandle_;
    };

    class CEO : public HandleInterface
    {
    public:
        CEO() = default;
        virtual ~CEO() = default;

    public:
        void handleRequest(float fDay) override {
            if (7 < fDay) {
                std::cout << "I will give you a long holiday!" << std::endl;
                return;
            }

            std::cout << fDay << "'s days leave has been permmited!" << std::endl;
        }
    };
} //tyrant

#endif //handleimpl.h
