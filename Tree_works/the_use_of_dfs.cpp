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
    bool hasPathSum(TreeNode* root, int targetSum) 
    {   
        if(root == nullptr)
        {
            return false;
        }
        if(root -> left == nullptr && root -> right == nullptr)
        //没有子节点，说明是叶子节点
        {
            return root->val == targetSum;
        }
        bool result_left = hasPathSum(root->left,targetSum-root->val);
        bool result_right = hasPathSum(root->right,targetSum-root->val);
        return result_left||result_right;
    }
};