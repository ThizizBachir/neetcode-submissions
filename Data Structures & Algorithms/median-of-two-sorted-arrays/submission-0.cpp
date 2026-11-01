class Solution {
public:
    double get_condidat(vector<int>& nums1,vector<int>& nums2, int a,int needed)
    {
        vector<int> & vfrom = a==1? nums1:nums2;
        vector<int> & vsecond = a==2? nums1:nums2;

        int n = vfrom.size();
        int m = vsecond.size();

        int l = 0;
        int h = n;

            while(h>l)
            {
                int mid =l+(h-l)/2;
                bool valid;
                int have;
                int have1 =  mid+1;
                int have2 =  upper_bound(vsecond.begin(), vsecond.end(),vfrom[mid]) - vsecond.begin();
                have = have1 + have2;
                valid = have>= needed; 
                if(valid) {h =mid;}
                else l = mid+1;

            }
            return h==n? INT_MAX :vfrom[h];


    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size();
        int m = nums2.size();
        int s = n+m;
        double result;
        if (s%2==1)
        {       
            int condidat1;
            int condidat2;
            int needed= (s)/2 +1;

            
            condidat1 = get_condidat(nums1,nums2,1,needed);
            condidat2 = get_condidat(nums1,nums2,2,needed);

            return result =  min(double(condidat1), double(condidat2));
        }

        else 
        {
            int condidat1;
            int condidat2;
            int needed= (s)/2;
            condidat1 = get_condidat(nums1,nums2,1,needed);
            condidat2 = get_condidat(nums1,nums2,2,needed);

            int x = min(double(condidat1), double(condidat2));

            int condidat3;
            int condidat4;
            needed= (s)/2 +1;

            
            condidat3 = get_condidat(nums1,nums2,1,needed);
            condidat4 = get_condidat(nums1,nums2,2,needed);

            int y = min(double(condidat3), double(condidat4));

            return (double(x) + double(y))/2;

        }
            
    }
};
