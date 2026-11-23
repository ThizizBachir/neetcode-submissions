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
    pair<int,int> solve(TreeNode * root)
    {
        if(!root) return {0,0};
        auto rsolve = solve(root->right);
        auto lsolve = solve(root->left);
        int rob = root->val + rsolve.second + lsolve.second ;
        int skip =max(rsolve.first,rsolve.second) + max(lsolve.first,lsolve.second) ;
        return {rob, skip};
    }
public:
    int rob(TreeNode* root) {
        return max(solve(root).first ,solve(root).second);
        
    }
};