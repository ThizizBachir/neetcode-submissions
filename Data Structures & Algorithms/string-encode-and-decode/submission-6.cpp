class Solution {
public:

    string encode(vector<string>& strs) {

        string s;
        for(auto& str : strs) s+=std::to_string(str.length()) +'#'+str;
        return s;

    }

    vector<string> decode(string s) {
        std::vector<string> strs;
        string str,len;
        
        int l;
        for(int i =0;i<s.length();i++){
            if('0'<=s[i] && s[i]<='9'){
                len+=s[i];
            }
            else if(s[i] == '#'){
                l = std::stoi(len);
                len.clear();
                str = s.substr(i+1,l);
                i+=l;
                strs.push_back(str);
            }


        }
            return strs;

    }
};
