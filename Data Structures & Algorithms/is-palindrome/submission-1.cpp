class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        char * l = s.data();
        char * r = s.data() + s.size()-1;

        while(l<r)
        {
            while (l<r && !isalnum((unsigned char)*l)) l++;
            while (l<r && !isalnum((unsigned char)*r)) r--;

            if(tolower((unsigned char)*l)!=tolower((unsigned char)*r))
            { return false; }
            
            l++;
            r--;

        }

        return true;

    }
};
