class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int *fast = &nums[0];
        int *slow = &nums[0];

        while ( true)
        {   
            fast = &nums [nums[*fast]];
            slow = &nums[*slow];
            if (fast == slow) break;
        }

        int * i = &nums[0];
        while(true)
        {
            i=&nums[*i];
            slow = & nums[*slow];
            if (i == slow) return i-nums.data();

        }


        
    }
};
