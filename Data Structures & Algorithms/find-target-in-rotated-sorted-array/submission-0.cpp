class Solution {
    bool isRight(const vector<int> & nums , int i)
    {
        return nums[i]<= nums.back();
    }

public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int minIndex;
        int low = 0;
        int high = n-1 ;
        while (low<high)
        {
            int mid = low + (high - low)/2;
            if (isRight(nums, mid)) high = mid;
            else low = mid+1;
        }

        minIndex = low;

        if(target == nums[minIndex]) return minIndex;

        low = target<= nums.back()? minIndex: 0;
        high = target<= nums.back() ? n-1 : minIndex-1;

        while (low<=high)
        {
            int mid = low + (high-low)/2;
            if ( target == nums[mid]) return mid;
            else if (target<nums[mid]) high = mid-1;
            else low = mid +1;
        }
        return -1;
        
    }
};
