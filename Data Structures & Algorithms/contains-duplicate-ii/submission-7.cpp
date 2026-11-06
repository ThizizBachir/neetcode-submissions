class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        int n = nums.size();

        set<int> s;
        int j = min(k+1, n);
        for(int i = 0;i<j;i++)
        {
            if(s.contains(nums[i])) return true;
            s.insert(nums[i]);
        }  
        int l =0;
        int r = k;  

        while(r+1<n)
        {
            l++;
            s.erase(nums[l-1]);
            r++;
            if(s.contains(nums[r])) return true;
            s.insert(nums[r]);
        }

        return false;
    }
};