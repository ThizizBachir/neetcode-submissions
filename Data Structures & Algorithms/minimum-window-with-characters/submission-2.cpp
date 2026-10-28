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

        for (auto c : t)
        {
            need[c - 'A']++;
        }

        have[s[0]-'A']++;

        int r =0;
        int l =0;

        while (r <n)
        {
            bool isValid = true;
            for ( int i =0;i<64;++i)
            {
                if(have[i]<need[i])
                {
                    isValid =  false;
                     break;
                }
            }
            
            if(isValid)
            {
                if (r-l+1<bestSize)
                {
                    bestSize = r-l+1;
                    bestL= l;
                }
                have[s[l]-'A']--;
                l++;

            }
            else
            {
                
                r++;
                if (r<n) have[s[r]-'A']++;
            }
        }   
        return (bestSize == INT_MAX) ? "" :s.substr(bestL,bestSize);
    }
};
