class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int l = 0;
        int h = n-1;

        while(l<h)
        {
            char c = s[l];
            s[l] = s[h];
            s[h] = c;
            l++;
            h--;
        }
        
    }
};