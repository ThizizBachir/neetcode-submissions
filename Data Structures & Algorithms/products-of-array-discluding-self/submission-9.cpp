class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int prod=1 ;
        std::set<int> zeros;
        for (int i=0;i<nums.size();++i){
            if (nums[i]==0){
                zeros.insert(i);
            }
            else{
                prod =prod *nums[i];
            }
        }

        if (zeros.size()>1){

            std::vector<int> answer0(nums.size(),0);
            return answer0;
        }

        if (zeros.size()==1){
            std::vector<int> answer0(nums.size(),0);
            answer0[*zeros.begin()] = prod;
            return answer0;
        };

        std::vector<int> answer(nums.size(),prod);

        for (int i=0;i<nums.size();++i){
            answer[i] = answer[i]/nums[i];
        }
        return answer;


    }
};
