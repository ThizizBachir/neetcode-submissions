class Solution {
public:
    bool isPal(char * l, char * r)
    {
        while(l<r)
        {   
            if(*l!=*r) return false;
            l++;
            r--;

        }


        return true;
    }
    bool validPalindrome(string s) {

        char * l = &s[0];
        char * r = &s[s.size()-1];

        while(l<r)
        {

            if (*l!=*r) return (isPal(l,r-1) || isPal(l+1,r) );
            l++;
            r--;

        }

        return true;



        
    }
};