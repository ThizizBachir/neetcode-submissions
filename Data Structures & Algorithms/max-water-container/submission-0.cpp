class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxA =0;
        int * l = heights.data();
        int * r =  heights.data()+heights.size() -1;
        while(l<r)
        {
            int Area = (r-l) * min(*r, *l);
            maxA = max(maxA,Area);
            if(*r>*l) l++;
            else if(*r<=*l) r--;
        }
        return maxA;
        
    }
};
