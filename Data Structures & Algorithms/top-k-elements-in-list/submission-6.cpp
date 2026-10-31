#include<map>
#include<vector>
#include<utility>
#include<algorithm>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        std::map<int,int> frq;
        for(auto n : nums){
            frq[n]++;
        }
        std::vector<std::pair<int,int>> vec(frq.begin(),frq.end());
        std::sort(vec.begin(),vec.end(),[](auto& a, auto& b){
            return a.second>b.second;
        });
        std::vector<int> answer;
        for (int i =0;i<k;i++){
            answer.push_back(vec[i].first);
        }
        return answer;


        
    }
};
