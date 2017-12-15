//组合模式：组合多个对象构成“部分-整体”的树形结构，使得客户对单个对象和复合对象的访问具有一致性
//适用条件：分层次的定义复杂对象，无需关心树形结构的区别

//main.cc

#include "composite.h"
#include "leaf.h"

int main()
{
    // 创建一个树形结构
    // 创建根节点
    auto pRoot = new ::tyrant::Composite("江湖公司（任我行）");

    // 创建分支
    auto pDepart1 = new ::tyrant::Composite("日月神教（东方不败）");
    pDepart1->Add(new ::tyrant::Leaf("光明左使（向问天）"));
    pDepart1->Add(new ::tyrant::Leaf("光明右使（曲洋）"));
    pRoot->Add(pDepart1);

    auto pDepart2 = new ::tyrant::Composite("五岳剑派（左冷蝉）");
    pDepart2->Add(new ::tyrant::Leaf("嵩山（左冷蝉）"));
    pDepart2->Add(new ::tyrant::Leaf("衡山（莫大）"));
    pDepart2->Add(new ::tyrant::Leaf("华山（岳不群）"));
    pDepart2->Add(new ::tyrant::Leaf("泰山（天门道长）"));
    pDepart2->Add(new ::tyrant::Leaf("恒山（定闲师太）"));
    pRoot->Add(pDepart2);

    // 添加和删除叶子
    pRoot->Add(new ::tyrant::Leaf("少林（方证大师）"));
    pRoot->Add(new ::tyrant::Leaf("武当（冲虚道长）"));
    auto *pLeaf = new ::tyrant::Leaf("青城（余沧海）");
    pRoot->Add(pLeaf);

    // 小丑，直接裁掉
    pRoot->Delete(pLeaf);

    // 递归地显示组织架构
    pRoot->Operation(1);

    // 删除分配的内存
    SAFE_DELETE(pRoot);

    return 0;
}
