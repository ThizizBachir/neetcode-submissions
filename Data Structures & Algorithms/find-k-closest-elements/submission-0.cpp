class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l =0;
        int r = n-1;
        vector<int> v;
        while(r-l>=k)
        {
            if(abs(x-arr[r])<abs(x-arr[l]))
            {
                l++;
                continue;
            }
            r--;
        }
        for ( int i = l;i<=r;++i)  v.push_back(arr[i]);
        return v;
        
    }
};