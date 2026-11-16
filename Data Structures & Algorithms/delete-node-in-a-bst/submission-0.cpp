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
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root) return nullptr;

        TreeNode ** p = key<root->val? &root->left:&root->right;

        if(root->val != key)
        {
            *p = deleteNode(*p,key);
            return root;
        }

        if(!root->left)
        {
            TreeNode * temp = root->right;
            delete root;
            return temp;
        }

        if(!root->right)
        {
            TreeNode * temp = root->left;
            delete root;
            return temp;
        }
        TreeNode * smallest = root->right;
        while(smallest->left) smallest= smallest->left;

        root->val = smallest->val;
        root->right = deleteNode(root->right,smallest->val);
        return root;
        




        
    }
};