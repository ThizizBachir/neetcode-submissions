class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l =0;
        int r = 0;
        int n = nums.size();
        int result =INT_MAX;
        int sum = nums[0];
        while(r<n && l<=r)
        {   
            
            if (sum<target)
            {
                r++;
                if(r<n)sum +=nums[r];
                continue;
            }
            if(sum>=target)
            {
                result=min(result,r-l+1);
                sum-=nums[l];
                l++;
                continue;
            }
            
        }
        if(result == INT_MAX) return 0;
        return result;
        
    }
};