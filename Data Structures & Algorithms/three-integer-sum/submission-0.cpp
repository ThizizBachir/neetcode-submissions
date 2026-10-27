class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3) return {};

        sort(nums.begin(),nums.end());
        int* fixed = nums.data();
        int *l = nums.data() + 1;
        int * r = nums.data() + nums.size()-1;
        vector<vector<int>> result;

        for (int * i = nums.data() ; i<nums.data() +nums.size()-2;++i)
        {
            if(*i>0) break;
            if(i!=nums.data() && *i == *(i-1)) continue;
            fixed = i;
            l= i+1;
            r=nums.data() + nums.size()-1;


            while(l<r)
            {
                int Sum = *i+*r+*l;
                if(Sum>0) r--;
                if(Sum<0) l++;
                if(Sum== 0)
                {
                    result.push_back({*i,*l,*r});
                    l++;
                    r--;
                    while(l<r && *l==*(l-1)) l++;
                    while(l<r && *r==*(r+1)) r--;
                }
            }

        }
        return result;

        
    }
};
