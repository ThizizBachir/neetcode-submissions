class Solution {
public:
    int get_condidat(vector<int>& nums1,vector<int>& nums2,int needed)
    {

        int n = nums1.size();

        int l = 0;
        int h = n;

        while(h>l)
        {
            int mid =l+(h-l)/2;
            bool valid;
            int have;
            int have1 =  mid+1;
            int have2 =  upper_bound(nums2.begin(), nums2.end(),nums1[mid]) - nums2.begin();
            have = have1 + have2;
            valid = have>= needed; 
            if(valid) {h =mid;}
            else l = mid+1;

        }
        return h==n? INT_MAX :nums1[h];


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

            
            condidat1 = get_condidat(nums1,nums2,needed);
            condidat2 = get_condidat(nums2,nums1,needed);

            return result =  min(double(condidat1), double(condidat2));
        }

        else 
        {
            int condidat1;
            int condidat2;
            int needed= (s)/2;
            condidat1 = get_condidat(nums1,nums2,needed);
            condidat2 = get_condidat(nums2,nums1,needed);

            int x = min(condidat1, condidat2);

            int condidat3;
            int condidat4;
            needed= (s)/2 +1;

            
            condidat3 = get_condidat(nums1,nums2,needed);
            condidat4 = get_condidat(nums2,nums1,needed);

            int y = min(condidat3, condidat4);

            return (x + y)/2.0;

        }
            
    }
};
