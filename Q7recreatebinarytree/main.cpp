#include <iostream>
#include <vector>
#include<algorithm>
#include<math.h>
using namespace std;
struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

vector<int> preOreder;
vector<int> inOrder;
BinaryTreeNode* createTree(int preStart, int preEnd,int inStart,int inEnd){
    BinaryTreeNode* root = new BinaryTreeNode();
    root->left = root->right = nullptr;
    int rootValue = preOreder[preStart];
    //如果为叶节点
    if(preStart == preEnd){
        if (inStart == inEnd && inOrder[inStart] == preOreder[preStart])
        {
            return root;
        }
        else 
            throw exception("Invaild Input");
    }
    int rootOrder = inStart;
    while(rootOrder <= inEnd && inOrder[rootOrder] != rootValue){
        ++rootOrder;
    }
    if(rootOrder == inEnd){
        throw exception("invaild Input");
    }

    int leftLength = rootOrder - inStart;

    if(leftLength > 0){
        root -> left = createTree(preStart + 1, preStart + leftLength,inStart,rootOrder - 1);
    }
    if(preStart + leftLength <= preEnd ){
        root ->right = createTree(preStart + leftLength + 1, preEnd,rootOrder + 1, inEnd);
    }
}
int main(){
    
    return 0;

}