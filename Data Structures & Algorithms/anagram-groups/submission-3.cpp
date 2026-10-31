class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> vs;
        unordered_map<string,int> m;
        int i =0;
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
                vector<string> * v = new vector<string>;
                v->push_back(str);
                m[sorted] = i;
                vs.push_back(*v);
                i++;

            }

        }

        return vs;
        
    }
};
