class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int n  = nums.size();
        int l = 0;
        int r = n-1;
        while(l<=r)
        {
            int mid = l+ (r-l)/2;
            int val = nums[mid];
            if(target == val) return mid;
            if(target>val){ l =mid+1;}
            else r=mid-1;
        }
        l=0;
        r = n;
        while(l<r)
        {
            int mid = l+ (r-l)/2;
            int val = nums[mid];

            if(val > target) {r=mid;}
            else l=mid+1;
        }
        return l;
        
    }
};