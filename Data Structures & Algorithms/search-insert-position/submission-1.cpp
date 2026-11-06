class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int n  = nums.size();
        int l = 0;
        int r = n;
        while(l<r)
        {
            int mid = l+ (r-l)/2;
            int val = nums[mid];

            if(val >= target) {r=mid;}
            else l=mid+1;
        }
        return l;
        
    }
};