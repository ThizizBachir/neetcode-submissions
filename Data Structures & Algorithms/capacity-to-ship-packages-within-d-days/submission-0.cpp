class Solution {
public:
    bool valid(vector<int>& weights, int days, int guess)
    {
        int avDays = days;
        int n =  weights.size();
        int sum  =0;
        int i=0;
        while(i<n)
        {
            sum +=weights[i];
            if(sum>guess)
            {
                avDays--;
                if(!avDays) return false;
                sum=0;
                continue;
            }
            i++;
        }
        return true;


    }
    int shipWithinDays(vector<int>& weights, int days)
    {
        int sum =0;
        int maxx = INT_MIN;
        for(int i :weights)
        {
            sum = sum+i;
            maxx = max(maxx,i);
        }
        int low = maxx;
        int high = sum;
        while(high>low)
        {
            int mid = low+ (high-low)/2;
            if(valid(weights,days,mid)) {high =mid;continue;}
            low = mid+1;
        }

        return high;
        
    }
};