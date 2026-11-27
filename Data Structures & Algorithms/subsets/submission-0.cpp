class Solution {
public:
    void dfs(vector<int>& nums, vector<int>& v,int depth,vector<vector<int>>& result)
    {
        if(depth == (int)nums.size()) 
        {
            result.push_back(v);
            return;
        }
        v.push_back(nums[depth]);
        dfs(nums,v,depth+1,result);
        v.pop_back();
        dfs(nums,v,depth+1,result);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res ={};
        vector<int> v ={};
        dfs(nums,v,0,res);
        return res;
        
    }
};
