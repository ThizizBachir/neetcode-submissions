class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        int n = nums.size();

        set<int> s;
        if(k>=n)
        {
            for(int i :nums)
            {
                if(s.contains(i)) return true;
                s.insert(i);
            }  
            return false;  

        }
        int l =0;
        int r = k;
        for(int i = l;i<=k;i++)
        {
            if(s.contains(nums[i])) return true;
            s.insert(nums[i]);
        }    

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