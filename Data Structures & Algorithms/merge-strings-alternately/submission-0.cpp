class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        auto a = word1.begin();
        auto b = word2.begin();
        while(true)
        {
            if(a!=word1.end()) {res.push_back(*a);a++;}
            if(b!=word2.end()) {res.push_back(*b);b++;}
            if(a==word1.end() && b==word2.end()) break;

        }
        return res;
        
    }
};