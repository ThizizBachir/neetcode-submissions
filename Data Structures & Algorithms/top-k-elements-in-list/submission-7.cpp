class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int> m;
        for (int i :nums) m[i]++;
        
        int n = nums.size();
        vector<vector<int>> f(n+1);
        for(auto & [key,val]: m) f[val].push_back(key);

        vector<int> result;

        for(int i =n;i>=1 && result.size()<k; i--)
        {
            for(int j :f[i]) result.push_back(j);
        }
        return result;


        
    }
};
