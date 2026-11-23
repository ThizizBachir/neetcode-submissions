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
    int maxRe(TreeNode* root,int& m)
    {
        if(!root) return 0;
        int mR = maxRe(root->right, m);
        int mL = maxRe(root->left, m);
        int mRL = max(mR+root->val,mL+root->val);
        mRL = max(mRL,root->val);
        m=max(m,mRL);
        m=max(m,mR+mL+root->val);
        m=max(m,root->val);
        return mRL;

    }
    int maxPathSum(TreeNode* root) {
        int m =INT_MIN;

        maxRe(root,m);
        return m;

    }
};
