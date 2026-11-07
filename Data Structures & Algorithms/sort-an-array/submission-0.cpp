class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        sort(nums.begin(),nums.end());
        for(int i:nums        ) v.push_back(i);

        return v;
    }
};