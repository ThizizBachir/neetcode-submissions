class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int sum;
        int * l = numbers.data();
        int * r = numbers.data() + numbers.size()-1;
        vector<int>  result;
        while(l<r)
        {
            sum = *l +*r;
            if ( target == sum)
            {
                result.push_back(l-numbers.data()+1);
                result.push_back(r-numbers.data()+1);
                return {static_cast<int>(l-numbers.data())+1,static_cast<int>(r-numbers.data())+1};
            }

            else if (target>sum) l++;
            else if (target<sum) r--;


        }
        
    }
};
