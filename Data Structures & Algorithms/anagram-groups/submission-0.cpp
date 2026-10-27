class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
    if (s.size() != t.size()) return false;

    int freq[26] = {0};  // Since input is lowercase English letters

    for (char c : s) freq[c - 'a']++;  // Increment for chars in 's'
    for (char c : t) freq[c - 'a']--;  // Decrement for chars in 't'

    for (int count : freq) {
        if (count != 0) return false;  // If any count is non-zero
    }

    return true;
}
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        for (int i=0;i<strs.size();i++){
            bool haveAnagram = false;
            for(int j=0;j<answer.size();j++){
                if(isAnagram(strs[i],answer[j][0])){
                    haveAnagram = true;
                    answer[j].push_back(strs[i]);
                    break;
                }
            }
            if(!haveAnagram){
                vector<string> newAnagramList;
                newAnagramList.push_back(strs[i]);
                answer.push_back(newAnagramList);

            }
        }
        return answer;
        
    }
};
