class Solution {
public:
    bool isSimplePalindrome(string s)
    {
        char * l = &s[0];
        char * r = &s[s.size()-1];
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

            if (*l!=*r)
            {
                string sub1(l, r );     
                string sub2(l+1, r+1 );     
                return (isSimplePalindrome(sub1) || isSimplePalindrome(sub2) );
            }
            else
            {
                l++;
                r--;
            }

        }

        return true;



        
    }
};