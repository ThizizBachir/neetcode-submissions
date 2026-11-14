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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int rv =  root->val;
        int pv = p->val;
        int qv = q->val;

        if(rv == pv || rv == qv) return root ;
        if((rv-pv) * (rv-qv) <0) return root;
        TreeNode* n = rv>pv? root->left : root->right;
        return lowestCommonAncestor(n, p, q);


        
    }
};
