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
    //这道题与105题有异曲同工之妙，只不过把前序序列转变成后序序列了
public:
    unordered_map<int,int>Map_val;
    vector<int>post;
    TreeNode * build(int in_start,int in_end,int post_start,int post_end)
    {
        //递归永远不要忘记设置终止条件
        if(post_start > post_end)
        {
            return nullptr;
        }
        //先找到根节点对应的值
        int root_val = post[post_end];
        TreeNode * root = new TreeNode(root_val); 
        //找到根节点在中序序列的位置
        int root_idx = Map_val[root_val];
        //求出左子树的长度
        int len_left_size = root_idx - in_start;
        root -> left = build(in_start,root_idx-1,post_start,post_start+len_left_size-1);
        root -> right = build(root_idx+1,in_end,post_start+len_left_size,post_end-1);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        post = postorder;
        for(int i = 0;i < inorder.size();i++)
        {
            Map_val[inorder[i]] = i;
        }
        return build(0,inorder.size()-1,0,postorder.size()-1);
    }
};