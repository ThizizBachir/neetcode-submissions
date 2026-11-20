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
    bool recursiveIsTargetLeaf(TreeNode * root , int target)
    {
        if(!root) return true;
        bool a = recursiveIsTargetLeaf(root->right,target);
        bool b = recursiveIsTargetLeaf(root->left,target);
        if(a)
        { 
            delete root->right;
            root->right = nullptr;
        }
        if(b)
        { 
            delete root->left;
            root->left = nullptr;
        }
        if(a && b && root->val == target)
        {
            return true;
        }
        return false;

    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool x = recursiveIsTargetLeaf(root,target);
        if(x) return nullptr;
        return root;
        
    }
};