#ifndef __BUILDER_PRODUCT_H__
#define __BUILDER_PRODUCT_H__

#include <string>

namespace tyrant
{
    //具体产品，由ConcreteBuilder提供建造
    class Computer
    {
        public:
            Computer() = default;
            ~Computer() =default;

            ::std::string GetCpu() { return Cpu_; }
            ::std::string GetMem() { return Mem_; }
            ::std::string GetMainBoard() { return MainBoard_; }
            ::std::string GetVideoCard() { return VideoCard_; }

            void SetCpu(::std::string Cpu) { Cpu_ = Cpu; }
            void SetMem(::std::string Mem) { Mem_ = Mem; }
            void SetMainBoard(::std::string MainBoard) { MainBoard_ = MainBoard; }
            void SetVedioCard(::std::string VideoCard) { VideoCard_ = VideoCard; }

        private:
            ::std::string Cpu_;
            ::std::string Mem_;
            ::std::string MainBoard_;
            ::std::string VideoCard_;
    };
}

#endif //__BUILDER_PRODUCT_H__
