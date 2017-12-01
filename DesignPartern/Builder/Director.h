#ifndef __BUILDER_DIRECTOR_H__
#define __BUILDER_DIRECTOR_H__

#include <memory>

#include "Builder.h"

namespace tyrant
{
    //提供创建具有buildxx的接口的类
    class Director
    {
        public:
            Director() = default;
            ~Director() = default;

            void Create(::std::shared_ptr<Builder_Interface> builder){
                builder->BuildCpu();
                builder->BuildMem();
                builder->BuildMainBoard();
                builder->BuildVedioCard();
            }
    };
}

#endif //__BUILDER_DIRECTOR_H__
