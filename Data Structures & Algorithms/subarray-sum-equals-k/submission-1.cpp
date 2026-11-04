class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> sums(n);
        sums[0] = nums[0];
        int result =0;
        for(int i =1;i<n;++i)
        {
            sums[i] = sums[i-1]+nums[i];

        }

        for(int i : sums) if(i ==k) result++;
        unordered_map<int, int> m;
        for(int i =0;i<n;++i)
        {
            if(m.contains(sums[i]-k)) result+= m[sums[i]-k];
            m[sums[i]]++;
        }
        return result; 
    }
};