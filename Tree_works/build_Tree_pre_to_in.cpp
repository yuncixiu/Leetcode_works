#include<iostream>
#include<vector>
#include<unordered_map>
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
public:
    unordered_map<int,int>Map_val;
    vector<int>pre;//用来存储前序序列数组
    vector<int>in;//用来存储中序序列数组，尽管好像没用到
    //思路：因为前序序列是[根左右]形式，第一个元素肯定是根节点,中序序列是[左根右]形式，可以用来分隔中序左子树和中序右子树.
    //因为我们要一直分割直到不能分割为止，所以可以用递归的方法
    //具体是root左根单独递归，传参是pre_idx(前序初始位置，一开始为0)，pre_idx + len_left_size(左子树的前序还是中序，长度一定是固定的,这个参数可以用两次)
    //in_idx中序初始位置，一开始是len_left_size + 1,in_end,就是数组长度减1

    TreeNode* build(int pre_start,int pre_end,int in_start,int in_end)
    {
        //递归的第一步永远是设置终止条件
        if(pre_start>pre_end)
        {
            return nullptr;
        }
        //先找到根节点的数值
        int root_val = pre[pre_start];
        //找到根节点在中序序列的位置，用于分隔并且找到左右子树长度
        int root_idx = Map_val[root_val];
        int len_left_size = root_idx - in_start;
        //记住二叉树建立在堆区，要new一个根节点
        TreeNode* root = new TreeNode(root_val); 
        //可以进行递归了build(前序左子树的起始，终止，中序左子树的起始，终止)
        root -> left = build(pre_start+1,pre_start+len_left_size,in_start,root_idx-1);
        root -> right = build(pre_start+len_left_size+1,pre_end,root_idx+1,in_end);
        return root;


    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
     //这里一定要用哈希表来存储数据，不然一直用循环的方式时间复杂度太高了,要用哈希表存储中序序列，为什么要用中序序列呢：那肯定是前序序列存储的是根节点，只有中序序列才能轻松分割
     pre = preorder;
     in = inorder;
     for(int i = 0;i < inorder.size();i++)
     {
        Map_val[inorder[i]] = i;
     } 
     return build(0,preorder.size()-1,0,inorder.size()-1);
    }
};