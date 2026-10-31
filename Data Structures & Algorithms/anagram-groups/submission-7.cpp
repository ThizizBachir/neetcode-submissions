class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> vs;
        unordered_map<string,int> m;
        for(auto str:strs)
        {
            string sorted = str;
            sort(sorted.begin(),sorted.end());
            if(m.contains(sorted))
            {
                vs[m[sorted]].push_back(str);
            }
            else
            {
                m[sorted] = vs.size();
                vs.push_back({str});
            }

        }

        return vs;
        
    }
};
