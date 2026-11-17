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

    void recursive(TreeNode * root , vector<int>& vec, int & reachedH , int currentH)
    {
        if(!root) return ;
        if(currentH>reachedH) 
        {
        reachedH++;
        vec.push_back(root->val);
        }
        if(root->right) recursive(root->right,vec,reachedH, currentH+1);
        if(root->left) recursive(root->left,vec,reachedH, currentH+1);
        return;

    }
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> vec;
        int reachedH = -1;
        recursive(root,vec,reachedH,0);
        return vec;
    }
};
