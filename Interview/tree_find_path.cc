#include <iostream>

#include <deque>

struct BSTreeNode
{
    int value_;
    BSTreeNode* left_;
    BSTreeNode* right_;

    BSTreeNode() : value_(0), left_(nullptr), right_(nullptr) {}
    ~BSTreeNode() = default;
};

void addBSTreeNode(BSTreeNode* & pTreeNode, int value)
{
    if (nullptr == pTreeNode) {
        pTreeNode = new BSTreeNode();
        pTreeNode->value_ = value;
    } else if (value < pTreeNode->value_) {
        addBSTreeNode(pTreeNode->left_, value);
    } else if (value > pTreeNode->value_){
        addBSTreeNode(pTreeNode->right_, value);
    } else {
        std::cout << "duplicated value" << std::endl;
    }
}

void findPath(BSTreeNode* pRoot, int nSum, const int nTarget)
{
    static std::deque<int> stack;

    if(pRoot == NULL)    return;
    if(nSum + pRoot->value_ == nTarget) {// 如果当前值加上路径和为目标值，则输出
        for(int i=0; i<stack.size(); i++)
            std::cout << stack[i] <<  "->";
        std::cout << pRoot->value_ << std::endl;
        return;
    } else if(nSum + pRoot->value_ > nTarget) {//如果大于目标值，则返回
         return;
    } else {// 如果小于，则入栈
        stack.push_back(pRoot->value_);
        nSum += pRoot->value_;
        findPath(pRoot->left_, nSum, nTarget);
        findPath(pRoot->right_, nSum, nTarget);
        nSum -= pRoot->value_;
        stack.pop_back();
    }

}
int main()
{
    BSTreeNode* pRoot = nullptr;

    addBSTreeNode(pRoot, 5);
    addBSTreeNode(pRoot, 2);
    addBSTreeNode(pRoot, 8);
    addBSTreeNode(pRoot, 6);
    addBSTreeNode(pRoot, 4);

    findPath(pRoot, 0, 13);
    return 0;
}
