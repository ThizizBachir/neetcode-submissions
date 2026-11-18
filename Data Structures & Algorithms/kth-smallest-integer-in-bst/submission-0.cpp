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
    void recursive(TreeNode* root ,int& i ,int& res, int k)
    {
        if(!root) return;
        recursive(root->left,i,res,k);
        i++;
        if (i==k) {res = root->val;return;}
        recursive(root->right,i,res,k);
        

    }
    int kthSmallest(TreeNode* root, int k) 
    {

        int i =0;
        int res;
        recursive(root,i,res,k);
        return res;    
    }
};
