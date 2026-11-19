class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(!n) return;
        if(!m)
        {
            for(int i =0;i<n;i++) nums1[i] = nums2[i];
            return;
        }
        auto a = nums1.begin();
        auto b = nums2.begin();
        while(a!=nums1.end())
        {
            if(min(*a,*b) == *a) {a++;continue;}
            int z = m + int(b - nums2.begin()); //first zero index
            while(z-1>=a-nums1.begin())
            {
                swap(nums1[z],nums1[z-1]);
                z--;
            }
            *a = *b;
            b++;
            if(b==nums2.end()) break;
            
        }
        if(b!=nums2.end())
        {
            int z = m + int(b - nums2.begin());
            for(int i =z;i<n+m;i++,b++) nums1[i] = *b;
        }

        return;
        
        
    }
};