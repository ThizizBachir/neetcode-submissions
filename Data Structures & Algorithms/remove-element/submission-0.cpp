class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        queue<int> freePlaces;
        int k = 0;
        for(int i = 0 ; i<n ;i++)
        {
            if(nums[i]!=val)
            {
                k++;
                if(!freePlaces.empty()) 
                {
                    nums[freePlaces.front()] = nums[i];
                    freePlaces.pop();
                    freePlaces.push(i);
                }
            }
            else
            {
                    freePlaces.push(i);
            }

        }
        return k;


        
    }
};