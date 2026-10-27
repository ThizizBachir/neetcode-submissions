class Solution {
public:

    long long  neededHour(vector<int>& piles , int k)
    {
        long long Hours=0;
        for (int i =0 ; i < piles.size(); i++  )
        {
            Hours += (piles[i] + (long long)k -1)/ k;
        }

        return Hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int maxPile = *max_element(piles.begin(), piles.end());
        int low = 1;
        int high = maxPile;
        while (low<high)
        {
            int mid = low + (high-low)/2;
            if (neededHour(piles,mid)<=h) high =mid;
            else if (neededHour(piles,mid) > h ) low = mid +1;
        }

        return low;
    }
};
