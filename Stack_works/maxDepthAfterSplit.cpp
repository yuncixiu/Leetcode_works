#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        //方法一:先用顺序遍历，然后就反转答案列表
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root == NULL)
        return ans;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int>temp;
            for(int i = 0;i < size;i++)
            {
                TreeNode * s = q.front();
                q.pop();
                if(s->left)
                q.push(s->left);
                if(s->right)
                q.push(s->right);
                temp.push_back(s->val);
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        

    }
};