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
    bool recursive(TreeNode * root, int min , int max)
    {
        if(!root) return true;
        if(root->val >= max || root->val <=min) return false;
        return recursive(root->right,root->val,max) && recursive(root->left,min,root->val);

    }
    bool isValidBST(TreeNode* root) 
    {
        int min = INT_MIN;
        int max = INT_MAX;
        return recursive (root, min , max);

    }
};
