class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cond1 = 0;
        int cond2 = 0;
        int count1 = 0;
        int count2 = 0;
        int n = nums.size();
        vector<int> res;
        for(auto i:nums)
        {
            if(cond1 == i) 
            {
                count1++;
                continue;
            }
            if(cond2 == i)
            {
                count2++;
                continue;
            }
            if(!count1)
            {
                cond1 =i;
                count1++;
                continue;
            }
            if(!count2)
            {
                cond2 =i;
                count2++;
                continue;
            }
            count1--;
            count2--;
        }

        count1 =0;
        count2 = 0;
        for(auto i :nums)
        {
            if(i==cond1){count1++;continue;}
            if(i==cond2){count2++;}
        }

        if(count1>n/3) res.push_back(cond1);
        if(count2>n/3) res.push_back(cond2);
        return res;
        
    }
};