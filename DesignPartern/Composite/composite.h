#ifndef __COMPOSITE_H_INCLUDED__
#define __COMPOSITE_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>

#include "component.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if (p) { delete p; p = NULL; } }

namespace tyrant
{
    //容器构件
    class Composite : public Component
    {
    public:
        Composite(::std::string sName) : Component(sName) {}
        virtual ~Composite() {
            for(::std::vector<Component*>::iterator it = ElementVec_.begin();
                it != ElementVec_.end();
                ++it) {
                SAFE_DELETE(*it);
                ElementVec_.erase(it);
            }
        }

    public:
        virtual void Add(Component* pComponent) {
            ElementVec_.push_back(pComponent);
        }

        virtual void Delete(Component* pComponent) {
            ::std::vector<Component*>::iterator it, itEnd;
            it      = ElementVec_.begin();
            itEnd   = ElementVec_.end();

            for(; it != itEnd; ++it) {
                if (pComponent == *it) {
                    SAFE_DELETE(*it);
                    ElementVec_.erase(it);
                }
            }
        }

        Component* GetChild(size_t nIndex) {
            if (ElementVec_.empty())
                return NULL;

            if (nIndex >= ElementVec_.size())
                return NULL;

            return ElementVec_[nIndex];
        }

        void Operation(int nIndent) override {
            ::std::string newStr(nIndent, '-');
            ::std::cout << newStr << "+ " << sName_ << ::std::endl;

            ::std::vector<Component*>::iterator it, itEnd;
            it      = ElementVec_.begin();
            itEnd   = ElementVec_.end();

            for (; itEnd != it; ++it)
                (*it)->Operation(nIndent + 2);
        }

    private:
        ::std::vector<Component*> ElementVec_;
    };
} //tyrant

#endif // SAFE_DELETE

#endif //__COMPOSITE_H_INCLUDED__
