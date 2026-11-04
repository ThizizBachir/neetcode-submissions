class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end() );
        int n = people.size();
        int low = 0;
        int high = n-1;
        int result = 0;

        while(low<high)
        {
            int weight = people[high]+people[low];
            if(weight>limit)
            {
                people[high] =0;
                high--;
                result++;
            }
            else
            {
                people[high] =0;
                people[low] =0;
                high--;
                low++;
                result ++;
            }
        }
        if(people[high]||people[low]) result++;

        return result;
        
    }
};