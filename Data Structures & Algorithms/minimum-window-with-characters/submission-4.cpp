class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size()>s.size()) return "";

        int n = s.size();
        int m = t.size();

        int need[64] = {};
        int have[64] = {};
        int bestSize=INT_MAX;
        int bestL=0;
        int required = 0;
        int formed =0;

        for (auto c : t)
        {
            if (need[c-'A'] == 0 ) required++;
            need[c - 'A']++;
        }

        have[s[0]-'A']++;
        if (have[s[0]-'A'] == need[s[0]-'A']) formed ++;

        int r =0;
        int l =0;

        while (r <n)
        {
            bool isValid = formed == required;
            
            if(isValid)
            {
                if (r-l+1<bestSize)
                {
                    bestSize = r-l+1;
                    bestL= l;
                }
                bool wasEqual = have[s[l]-'A'] == need[s[l]-'A'];
                have[s[l]-'A']--;
                if(wasEqual) formed--;
                l++;

            }
            else
            {
                
                r++;
                if (r<n)
                {
                    have[s[r]-'A']++;
                    if (have[s[r]-'A'] == need[s[r]-'A']) formed ++;
                }
                    
            }
        }   
        return (bestSize == INT_MAX) ? "" :s.substr(bestL,bestSize);
    }
};
