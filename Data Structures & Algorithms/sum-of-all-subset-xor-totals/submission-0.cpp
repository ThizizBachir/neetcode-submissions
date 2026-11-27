class Solution {
public:
    int dfs(vector<int> & nums, int i ,int res)
    {   
        if(i== (int)nums.size()) return res;
        return dfs(nums,i+1,res ^ nums[i]) + dfs(nums,i+1,res);
    }
    int subsetXORSum(vector<int>& nums) 
    {
        return dfs(nums,0,0);
        
    }
};