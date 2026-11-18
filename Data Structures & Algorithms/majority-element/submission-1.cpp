class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = nums[0];
        int rep = 1;
        int n = nums.size();
        for(int i = 1;i<n;i++)
        {
            if (val == nums[i]) 
            {
                rep++;
                continue;
            }
            rep--;
            if(!rep) 
            { 
                val  = nums[i];
                rep ++;
            }
            
        }

        return val;
        
    }
};