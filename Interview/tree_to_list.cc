//中序遍历二叉树转换成双向链表
#include <iostream>

struct BSTreeNode
{
    int         nValue_;
    BSTreeNode* pLeft_;
    BSTreeNode* pRight_;

    BSTreeNode() : nValue_(0), pLeft_(nullptr), pRight_(nullptr)
    {}
    ~BSTreeNode() = default;
};

void addBSTreeNode(BSTreeNode*& pBSTreeNode, int nValue);
void inOrderBSTree(BSTreeNode* pBSTreeRoot);
void convertBSTreeToBiLinkedList(BSTreeNode* pCurrent);

//链表的头节点
BSTreeNode* pHead = nullptr;
//当前链表的尾节点
BSTreeNode* pTail = nullptr;

int main()
{
    BSTreeNode* pRoot = nullptr;
    addBSTreeNode(pRoot, 10);
    addBSTreeNode(pRoot, 6);
    addBSTreeNode(pRoot, 14);
    addBSTreeNode(pRoot, 4);
    addBSTreeNode(pRoot, 8);
    addBSTreeNode(pRoot, 12);
    addBSTreeNode(pRoot, 16);

    inOrderBSTree(pRoot);

    while (nullptr != pHead){
        ::std::cout << " " << pHead->nValue_;
        pHead = pHead->pRight_;
    }

    return 0;
}

//添加二叉树节点
void addBSTreeNode(BSTreeNode*& pBSTreeNode, int nValue)
{
    //空二叉树
    if (nullptr == pBSTreeNode) {
        pBSTreeNode = new BSTreeNode();
        pBSTreeNode->nValue_    = nValue;
        pBSTreeNode->pLeft_     = nullptr;
        pBSTreeNode->pRight_    = nullptr;
    } else if (nValue < pBSTreeNode->nValue_) {
        addBSTreeNode(pBSTreeNode->pLeft_, nValue);
    } else if (nValue > pBSTreeNode->nValue_) {
        addBSTreeNode(pBSTreeNode->pRight_, nValue);
    } else {
        ::std::cout << "duplicated value!" << ::std::endl;
    }
}

//中序遍历二叉树
void inOrderBSTree(BSTreeNode* pBSTreeRoot)
{
    // 无二叉树， 不做处理
    if (nullptr == pBSTreeRoot) {
        return;
    }

    if (nullptr != pBSTreeRoot->pLeft_) {
        inOrderBSTree(pBSTreeRoot->pLeft_);
    }

    convertBSTreeToBiLinkedList(pBSTreeRoot);

    if (nullptr != pBSTreeRoot->pRight_) {
        inOrderBSTree(pBSTreeRoot->pRight_);
    }
}

//将二叉树转换成双向循环链表
void convertBSTreeToBiLinkedList(BSTreeNode* pCurrent)
{
    if (nullptr == pCurrent)
        return;

    //将当前二叉树的节点的左孩子指针指向链表的尾节点
    pCurrent->pLeft_ = pTail;
    if (nullptr == pCurrent->pLeft_) {
        //此时链表尚未建立，将当前节点设为链表头节点
        pHead = pCurrent;
    } else {
        //把当前节点赋给链表的右指针
        pTail->pRight_ = pCurrent;
    }

    //将当前节点设置为链表尾节点
    pTail= pCurrent;

}
