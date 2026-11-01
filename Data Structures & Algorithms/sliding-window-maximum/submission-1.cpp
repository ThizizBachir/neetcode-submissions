class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        deque<pair<int,int>> d;
        int l =0;
        int r =0;
        while(r<k)
        {
            while(!d.empty() && nums[r]>d.back().first )
            {
                d.pop_back();
            }
            d.push_back({nums[r],r});
            r++;
        }

        result.push_back(d.front().first);
        r--;
        while(r<n-1)
        {
            r++;
            l++;

            if(!d.empty() && l>d.front().second) d.pop_front();
            while(!d.empty() && nums[r]>d.back().first )
            {
                    d.pop_back();
            }
            d.push_back({nums[r],r});

            result.push_back(d.front().first);
        }
        return result;
        
    }
};
