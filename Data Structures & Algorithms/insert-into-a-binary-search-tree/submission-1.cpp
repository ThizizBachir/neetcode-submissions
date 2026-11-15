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
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if(!root)
        {
            TreeNode * node= new TreeNode(val);

            return node;
        }
        TreeNode * rORl = val>root->val? root->right:root->left;
        TreeNode ** prORl =  val>root->val? &root->right : &root->left;

        if(!rORl)
        {
            TreeNode * node = new TreeNode(val);
            *prORl = node;
            return root;
        }

        insertIntoBST(rORl,val);
        return root;
        
        
    }
};