class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {

        int cnt[26] = {};
        int n = s1.size();
        int nn = s2.size();
        int l = 0;
        if(n>nn) return false;
        for (int i =0; i<n;++i)
        {
            ++cnt[s1[i]-'a'];
            --cnt[s2[i]-'a'];

        }
        bool out = true;
        for(int j =0;j<26;++j) out = out && cnt[j]==0;
        if (out )return out;
        for (int r =n; r<nn;++r)
        {
            out = true;
            ++l;
            ++cnt[s2[l-1]-'a'];
            --cnt[s2[r]-'a'];
             for(int j =0;j<26;++j)
             { out = out && cnt[j]==0;}
             if (out )return out;
            
        }
        return false;
        
    }
};
