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
    void helper(TreeNode* root , int& diam)
    {
        recursionFunction(root , diam);
    }

    int recursionFunction(TreeNode* root , int& diam)
    {
        if (!root || (!root->right && !root->left)) return 0;

        if(!root->right || !root->left )
        {
            TreeNode * validSide = root->right? root->right:root->left;
            int height = 1 + recursionFunction(validSide,diam);
            diam = max(diam,height);
            return height;
        } 
            
        int heightRight = 1 + recursionFunction(root->right,diam);
        int heightLeft = 1 + recursionFunction(root->left,diam);

        diam = max(diam,heightRight+heightLeft);
        return max(heightRight,heightLeft);
        
        

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diam = 0;
        helper(root,diam);
        return diam;

        
    }
};
