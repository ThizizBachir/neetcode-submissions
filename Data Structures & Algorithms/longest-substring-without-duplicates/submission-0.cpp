class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int result =0;
        unordered_map<char, int> charIndex;
        int l =0;
        for (int r = 0 ; r<n;r++)
        {
            if(!charIndex.contains(s[r]))
            {
                charIndex[s[r]] = r;
            }
            else 
            {
                int oldIndex = charIndex[s[r]];
                charIndex[s[r]] = r;
                l = max(l,oldIndex+1);
            }


            result = max(result , r-l+1);
        }
        return result;
        
    }
};
