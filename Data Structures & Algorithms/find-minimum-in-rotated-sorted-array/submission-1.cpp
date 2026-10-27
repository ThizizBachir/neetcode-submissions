class Solution {
public:
    bool inRightPart(vector<int> & nums , int i)
    {
        if (nums.size()<=1) return true;
        if (i == nums.size() -1 ) return true;
        return nums[i]<nums[nums.size() -1];
    }
    int findMin(vector<int> &nums) {

        int r = nums.size()-1;
        int l  = 0;

        while (r>l)
        {
            int mid = l+ (r-l)/2;
            if ( inRightPart(nums,mid)) r = mid;
            else l = mid+1;
        }


        return nums[r];
    }
};
