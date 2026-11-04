class Solution {
public:
    void reverse(int * i, int * j)
    {
        while(i<j)
        {
            int c = *i;
            *i = *j;
            *j = c;

            i++;
            j--;
        }
        return;
    }
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        k =k % n;

        if(!k) return;

        int * i = &nums[0];
        int * j = &nums[n-1];

        reverse(i,j);
        reverse(i,i+k-1);
        reverse(&nums[k],j);

        return;
    }
};