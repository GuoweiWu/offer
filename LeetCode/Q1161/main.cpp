#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

const int MAX_N = 1000;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxLevelSum(TreeNode *root)
{
    queue<TreeNode *> que;
    int nowLevel = 1;
    int rest = 1;
    int tempResult = 0;
    int resultLevel = 1;
    int nextRest = 0;
    int result = 0;
    que.push(root);
    while (!que.empty())
    {
        TreeNode *now = que.front();
        rest--;
        tempResult += now->val;
        que.pop();
        if (now->left != nullptr)
        {
            que.push(now->left);
        }
        if (now->right != nullptr)
        {
            que.push(now->right);
        }
        if (rest == 0)
        {
            if (tempResult > result)
            {
                result = tempResult;
                resultLevel = nowLevel;
            }
            nowLevel++;
            tempResult = 0;
            rest = que.size();
        }
    }
    return resultLevel;
}

int main()
{
}