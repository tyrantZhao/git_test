//main.cc
//责任链模式，对于一组对象，将这些对象组成链条，使得每个请求会沿着这条链条移动，保证有一个链条会进行处理
//适用场所，请求可能被多个对象处理，使用者无需关心谁在处理这个请求
#include "handleimpl.h"


using namespace tyrant;

int main() {
    auto pManager   = new Manager();
    auto pDirector  = new Director();
    auto pCEO       = new CEO();

    //构建职责链
    pManager->setHandle(pDirector);
    pDirector->setHandle(pCEO);

    //请假
    pManager->handleRequest(1);
    pManager->handleRequest(2);
    pManager->handleRequest(5);
    pManager->handleRequest(10);

    if (pManager) {
        delete pManager;
        pManager = nullptr;
    }

    return 0;
}
