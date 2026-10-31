class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1;
        int nz =0;

        vector<int> v;

        for(int i : nums)
        {
            if (!i)
            {
                nz++;
                continue;
            }
            prod = prod*i;
            if(nz>1) break;
        }

        for (int i : nums)
        {
            if(nz>1) {v.push_back(0); }
            else if(nz == 1)
            {
                if (!i) { v.push_back(prod); continue;}
                else    { v.push_back(0); continue;}
            }
            else v.push_back(prod/i); 
        }

        return v;
    }
};
