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
    int height(TreeNode * side)
    {   
        if(!side) return 0;

        return 1 + max(height(side->right),height(side->left));

    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        if(abs(height(root->right) - height(root->left))<=1) return (isBalanced(root->right) && isBalanced(root->left));
        return false;
        
    }
};
