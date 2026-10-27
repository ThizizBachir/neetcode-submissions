#include <map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        int l = s.size();
        if (s.size() != t.size()) return false;

        std::map<char,int> maps;
        std::map<char,int> mapt;
        for (char c ='a'; c<='z';c++){
            maps[c]=0;
            mapt[c]=0;
        }
        for ( int i =0 ;i<l;i++){
            maps[s[i]]++;
            mapt[t[i]]++;
        }
        for (char c ='a'; c<='z';c++){
            if(maps[c]!=mapt[c]){
                return false;
            }
        } 
        return true;



        
    }
};
