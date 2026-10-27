class Solution {
public:

    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int res =0;
        int * l = height.data();
        int * r = height.data() + height.size() -1;
        int * i;

        int maxleft = 0;
        int maxright = 0;


        while (l<r)
        {
            maxleft = max(maxleft, *l);
            maxright = max(maxright , *r);

            i = (maxleft >= maxright) ? r:l; 
            int water = max( 0, min(maxleft , maxright) - *i);
            res+= water;
            l+= (i==l) ? 1:0;
            r-= (i==r) ? 1:0;

        }
        return res;
    }
};
