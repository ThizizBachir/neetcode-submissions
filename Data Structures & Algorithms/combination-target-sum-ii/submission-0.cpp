class Solution {
public:
    void dfs(vector<pair<int,int>>& v, int target ,vector<int>& path,int sum , int depth , vector<vector<int>>& res)
    {
        if(sum == target)
        {
            res.push_back(path);
            return;
        }
 
        if(depth == (int)v.size() || sum>target) return;
        dfs(v,target,path,sum,depth+1,res);
        int counter =0;
        while(counter<v[depth].second)
        {
            sum+=v[depth].first;
            if(sum>target) break;
            counter++;
            path.push_back(v[depth].first);
            dfs(v,target,path,sum,depth+1,res);
        }

        while(counter) { path.pop_back(); counter--;}
        return;


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int,int> m;
        for(int i : candidates) m[i]++;
        vector<pair<int,int>> v;
        for(const auto& [key,value] :m) v.push_back({key,value});

        vector<vector<int>> res;
        vector<int> path;
        dfs(v,target,path,0,0,res);
        return res;


        
    }
};
