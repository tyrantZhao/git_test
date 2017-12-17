#ifndef __FACADE_SUBSYS_H_INCLUDED__
#define __FACADE_SUBSYS_H_INCLUDED__

#include <string>
#include <iostream>
#include <thread>
#include <chrono>

namespace tyrant {
    const ::std::string sStateToStrCourier[] = { "收到", "验证可达性", "分配人员", "派送包裹", "获取交货确认", "完成" };
    const ::std::string sStateToStrVendor[] = { "收到", "确认库存", "从仓库得到物品", "包装", "联系快递员", "完成" };
    const ::std::string sStateToStrOrderTeam[] = { "收到", "确认付款", "联系供应商", "完成" };

    // 订单团队
    class OrderTeam
    {
    public:
        void submitRequest() {
            State_ = 0;
        }

        // 检测状态
        bool checkStatus() {
            ::std::cout << "订单团队 - 当前状态：" << sStateToStrOrderTeam[State_] << ::std::endl;

        ::std::this_thread::sleep_for(::std::chrono::seconds(3));
        State_++;

        return (State_ == Complete);
        }

    private:
        enum States {
            Received,  // 收到
            VerifyPayment,  // 确认付款
            ContactVendor,  // 联系供应商
            Complete  // 完成
        };
        int State_;
    };

    // 供应商
    class Vendor
    {
    public:
        void submitRequest() {
            State_ = 0;
        }

        // 检测状态
        bool checkStatus() {
            ::std::cout << "供应商 - 当前状态：" << sStateToStrVendor[State_] << ::std::endl;

            ::std::this_thread::sleep_for(::std::chrono::seconds(1));
            State_++;

            return (State_ == Complete);
        }

    private:
        enum States {
            Received,  // 收到
            VerifyInventory,  // 确认库存
            GetItemFromWareHouse,  // 从仓库得到物品
            PackItem,  // 包装
            ContactCourier,  // 联系快递员
            Complete  // 完成
        };
        int State_;
    };

    // 快递员
    class Courier
    {
    public:
        // 将请求转发给快递员
        void submitRequest() {
            State_ = 0;
        }

        // 检测状态
        bool checkStatus() {
            ::std::cout << "快递员 - 当前状态：" << sStateToStrCourier[State_] << ::std::endl;

            ::std::this_thread::sleep_for(::std::chrono::seconds(1));
            State_++;

            return (State_ == Complete);
        }

    private:
        enum States {
            Received,  // 收到
            VerifyReachbility,  // 验证可达性
            AssignPerson,  // 分配人员
            DispatchPackage,  // 派送包裹
            GetDeliveryConfirmation,  // 获取交货确认
            Complete  // 完成
        };
        int State_;
    };
} //tyrant

#endif //subsys.h
