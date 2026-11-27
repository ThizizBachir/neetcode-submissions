class Solution {
public:
    void dfs(vector<int>& nums,int target,vector<int>& path , int sum , int depth , vector<vector<int>>& res)
    {
        
        if(sum == target)
        {
            res.push_back(path);
            return;
        }
        if(depth == (int)nums.size())
        {
            return;
        }

        dfs(nums,target,path,sum,depth+1,res);
        int i =0;
        while(true)
        {
            sum+=nums[depth];
            if(sum>target) break;
            i++;
            path.push_back(nums[depth]);
            dfs(nums,target,path,sum,depth+1,res);
        }

        while(i)
        {
            path.pop_back();
            i--;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>> res;
        vector<int> path;
        dfs(nums,target,path,0,0,res);
        return res;
        
    }
};
