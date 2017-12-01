#ifndef __BUILDER_BUILDER_H__
#define __BUILDER_BUILDER_H__

#include "Computer.h"

namespace tyrant
{

    //用以提供一个构建产品的各部分零件的抽象接口
    class Builder_Interface
    {
        public:
            Builder_Interface() = default;
            virtual ~Builder_Interface() = default;

            //构建CPU
            virtual void BuildCpu() = 0;
            //构建内存
            virtual void BuildMem() = 0;
            //构建主板
            virtual void BuildMainBoard() = 0;
            //构建显卡
            virtual void BuildVedioCard() = 0;
            //产品索引
            virtual Computer* GetResult() = 0;
    };

    //ThinkPad产品
    class TpBuilder : public Builder_Interface
    {
        public:
            TpBuilder() { TpComputer_ = new Computer(); }
            virtual ~TpBuilder() { if(TpComputer_) delete TpComputer_; TpComputer_ = nullptr; }

            virtual void BuildCpu() { TpComputer_->SetCpu(" Intel i5"); }
            virtual void BuildMem() { TpComputer_->SetMem("DDR5"); }
            virtual void BuildMainBoard() { TpComputer_->SetMainBoard("ThinkPad"); }
            virtual void BuildVedioCard() { TpComputer_->SetVedioCard("NVDIA Geforce 994"); }
            virtual Computer* GetResult() { return TpComputer_; }

        private:
            Computer* TpComputer_;
    };

    //Yoga产品
    class YogaBuilder : public Builder_Interface
    {
        public:
            YogaBuilder() { YogaComputer_ = new Computer(); }
            virtual ~YogaBuilder() { if(YogaComputer_) delete YogaComputer_; YogaComputer_ = nullptr; }

            virtual void BuildCpu() { YogaComputer_->SetCpu(" Intel i5"); }
            virtual void BuildMem() { YogaComputer_->SetMem("DDR5"); }
            virtual void BuildMainBoard() { YogaComputer_->SetMainBoard("ThinkPad"); }
            virtual void BuildVedioCard() { YogaComputer_->SetVedioCard("NVDIA Geforce 994"); }
            virtual Computer* GetResult() { return YogaComputer_; }

        private:
            Computer* YogaComputer_;
    };
}

#endif //__BUILDER_BUILDER_H__
