class Solution {
public:
    void dfs(int n , int k , vector<int>& path,int depth,vector<vector<int>>& res)
    {
        if((int)path.size() == k)
        {
            res.push_back(path);
            return;
        }
        if(depth>n) return;

        path.push_back(depth);
        dfs(n,k,path,depth+1,res);
        path.pop_back();
        dfs(n,k,path,depth+1,res);
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> res;
        vector<int> path;
        dfs(n,k,path,1,res);
        return res;
    }
};