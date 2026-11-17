/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void recursive(TreeNode * root, int& res,int max)
    {
        if(!root) return;
        if(root->val>=max) 
        {
            max = root->val;
            res++;
        }
        recursive(root->right,res,max);
        recursive(root->left,res,max);
        return;
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int res =1;
        int max = root->val;
        recursive(root->right,res,max);
        recursive(root->left,res,max);
        return res;
    }
};
