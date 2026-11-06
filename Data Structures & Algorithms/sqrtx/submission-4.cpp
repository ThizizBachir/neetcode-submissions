class Solution {
public:
    int mySqrt(int x) {
        int l =0;
        int r = x;
        while(l<r)
        {
            long long mid = l + (r-l)/2;
            if(mid*mid>x) {r=mid;}
            else l=mid+1;

        }
        if(x==1) return 1;
        return max (0,r-1);
        
    }
};