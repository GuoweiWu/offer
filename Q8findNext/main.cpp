#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct BinaryTreeNode
{
    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode *parent;
};

BinaryTreeNode *GetNext(BinaryTreeNode *pNode)
{
    if (pNode == nullptr)
    {
        return nullptr;
    }

    BinaryTreeNode *pNext = nullptr;
    if (pNode->right != nullptr)
    {
        BinaryTreeNode* pRight = pNode->right;
        while (pNode->left!=nullptr)
        {
            pRight = pRight ->left;
        }

        pNext = pRight;
    }
    else if(pNode->parent!=nullptr){
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->parent;
        while (pParent!=nullptr&&pCurrent == pParent->right)
        {
            pCurrent = pParent;
            pParent = pParent->parent;
        }
        pNext = pParent;
    }
    return pNext;
}