#ifndef __FACADE_FACADE_H_INCLUDED__
#define __FACADE_FACADE_H_INCLUDED__

#include "subsys.h"

namespace tyrant
{
    // 网购外观
    class OnlineShoppingFacade
    {
    public:
        OnlineShoppingFacade() {
            Count_ = 0;
        }

        // 返回跟踪次数
        int followupNum() {
            return Count_;
        }

        // 提交订单
        void submitRequest() {
            State_ = 0;
        }

        // 跟踪订单
        bool checkStatus(){
            // 收到订单请求
            switch (State_) {
            case Received:
                {
                    State_++;
                    // 将请求转发给订单团队
                    Order_.submitRequest();
                    ::std::cout << "********** 提交给订单团队，跟踪次数：" << Count_ << " **********" << ::std::endl;
                }
                break;
            case SubmittedToOrderTeam:
                {
                    // 如果订单团队完成验证，则向供应商发出请求
                    if (Order_.checkStatus()) {
                        State_++;
                        Vendor_.submitRequest();
                        ::std::cout << "********** 提交给供应商，跟踪次数：" << Count_ << " **********" << ::std::endl;
                    }
                }
                break;
        case SubmittedToVendor:
            {
                // 如果供应商已将包裹打包，将其转发给快递员
                if (Vendor_.checkStatus()) {
                    State_++;
                    Courier_.submitRequest();
                    ::std::cout << "********** 提交给快递员，跟踪次数：" << Count_ << " **********" << ::std::endl;
                }
            }
            break;
        case SubmittedToCourier:
            {
                // 如果包裹交付，订单完成
                if (Courier_.checkStatus())
                    return true;
            }
            break;
        default:
            break;
        }

        Count_++;

        // 订单未完成
        return false;
    }

    private:
        enum States {
            Received,  // 收到
            SubmittedToOrderTeam,  // 提交给订单团队
            SubmittedToVendor,  // 提交给供应商
            SubmittedToCourier  // 提交给快递员
        };

        int State_;  // 订单状态
        int Count_;  // 跟踪次数

        OrderTeam Order_;
        Vendor Vendor_;
        Courier Courier_;
    };
} //tyrant

#endif //facade.h
