class Solution {
public:
    void push(vector<vector<int>>& v, vector<int>& in)
    {
        bool exist = false;
        for(auto x:v)
        {
            exist = exist || (x[0] == in[0] && x[1] == in[1] && x[2] == in[2] && x[3] == in[3]);
        }

        if(exist) return;

        v.push_back(in);

    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());
        
        int  n = nums.size();
        if(n<4) return {};
        vector<vector<int>> v;

        for(int i = 0 ; i<n-3;++i)
        {
            for(int j= i+1 ; j<n-2;++j)
            {
                int k = j+1;
                int l = n-1;
                while(k<l)
                {
                    long long sum = (long long) nums[i]+nums[j]+nums[k]+nums[l] ;
                    if(sum == target) 
                    {
                        vector<int>  in ={nums[i],nums[j],nums[k],nums[l]};
                        push(v,in);
                        k++;
                        l--;
                    }

                    if(sum>target) l--;
                    if(sum<target) k++;
                }
            }
            
        }

        return v;
        

        
    }
};