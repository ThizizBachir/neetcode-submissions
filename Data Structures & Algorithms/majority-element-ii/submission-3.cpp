class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cond1 = 0;
        int cond2 = 0;
        int count1 = 0;
        int count2 = 0;
        int n = nums.size();
        vector<int> res;

        for(int i=0;i<n;i++)
        {
            if(nums[i] == cond1){count1++;continue;}
            if(nums[i] == cond2){count2++;continue;}
            if(!count1) {count1++;cond1=nums[i];continue;}
            if(!count2) {count2++;cond2=nums[i];continue;}            
            count1--;
            count2--;
        }

        count1=0;
        count2=0;
        for(int x :nums)
        {
            if(x==cond1) count1++;
            else if(x==cond2) count2++;
        }

        if(count1>n/3) res.push_back(cond1);
        if(count2>n/3) res.push_back(cond2);
        return res;
        
    }
};