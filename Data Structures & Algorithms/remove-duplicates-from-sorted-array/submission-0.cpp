class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k =1;
        int last =nums[0];

        for(int i =1;i<n;++i)
        {
            if(nums[i] == last) continue;
            last = nums[i];
            nums[k] = last;
            k++;
        }
        return k;
        
    }
};