#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
void dfs(TreeNode*root,vector<int> & ans)
{
    if(root == NULL)
    {
        ans.push_back(INT_MAX);
        return;
    }
    ans.push_back(root->val);
    dfs(root->left,ans);
    dfs(root->right,ans);
}
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
     //这道题主要考查了二叉树的遍历，更准确的来说，任意四种遍历{前序遍历，中序遍历，后序遍历和层次遍历都可以}
     //首先定义一个dfs函数，这里我采用前序遍历. 
     //必须在函数外面用引用传递ans，如果定义在函数内部，每次递归都会拷贝一份ans，导致最终得到的ans是真正答案的切片
     vector<int>ans1;  
     //递归结束，比较得到的ans1和ans2是否相等
     vector<int>ans2;
     dfs(p,ans1);
     dfs(q,ans2);
     return ans1 == ans2;
    }
};