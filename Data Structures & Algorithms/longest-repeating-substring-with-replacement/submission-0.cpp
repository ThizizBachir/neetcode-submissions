class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int cnt[26] ={};
        int l =0;
        int n = s.size();
        int result =0;
        for(int r = 0; r<n;r++)
        {
            ++cnt[s[r]-'A'];
            while ((r-l+1 - *max_element(cnt, cnt +26) )>k)
            {
                --cnt[s[l]-'A'];
                ++l;
            }
            result = max(result , r-l+1);
        }

        return result;
        
    }
};
