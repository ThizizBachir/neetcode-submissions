class Solution {
public:
    string decodeString(string s) {
        stack<char> sc;
        for(char c :s)
        {
            if(isalnum(c) || c=='[')
            {
                sc.push(c);
                continue;
            }
            else if (c ==']')
            {
                string stToR="";
                while(!sc.empty() && isalpha(sc.top()))
                {
                    stToR.push_back(sc.top());
                    sc.pop();
                }
                sc.pop();
                reverse(stToR.begin(),stToR.end());
                string stToN = "";
                while(!sc.empty() &&isdigit(sc.top()))
                {
                    stToN.push_back(sc.top());
                    sc.pop();
                }
                reverse(stToN.begin(),stToN.end());

                int m = stoi(stToN);
                string finalString ="";
                for(int i =0;i<m;++i) finalString += stToR;

                for(char cc : finalString) sc.push(cc);



            }
            
        }

        string result ="";
        while(!sc.empty())
        {
            result.push_back(sc.top());
            sc.pop();
        }

        reverse(result.begin(),result.end());

        return result;
    }
};