class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for(auto str:strs)
        {
            string dummyPrefix;
            int i =0;
            while(i<min(prefix.size(),str.size()))
            {
                if(prefix[i]==str[i]) {dummyPrefix.push_back(prefix[i]);i++;}
                else break;
            }
            prefix = dummyPrefix;

        }
        return prefix;
    }
};