class Solution {
public:
    bool isAnagram(string s, string t) {
        array<int,26> arr;

        for(auto c : s)
        {
            arr[c-'a']++;
        }
        for(auto c : t)
        {
            arr[c-'a']--;
            if (arr[c-'a']<0) return false;
        }

        for(int i :arr)
        {
            if (i!= 0) return false;
        }
        return true;
    }
};
