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

    void levelOrderR(TreeNode* root,vector<vector<int>>& vec,int index )
    {
        if(!root) return;
        if(vec.size() == index) vec.push_back({});
        vec[index].push_back(root->val);
        levelOrderR(root->left,vec,index+1 );
        levelOrderR(root->right,vec,index+1 );
        


    }
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> vec;
        levelOrderR(root,vec,0);
        return vec;
    }
};
