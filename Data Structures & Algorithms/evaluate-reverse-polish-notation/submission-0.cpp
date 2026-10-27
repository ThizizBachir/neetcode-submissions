class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> st;
        int a ;
        int b;
        for (const auto& t:tokens)
        {
            bool isop =  t.length() ==1 && string("+/-*").find(t[0]) != string::npos;
            if (!isop)
            {
                st.push(stoi(t));
                continue;
            }

            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            
            switch(t[0])
            {
                case '+':
                    st.push(a+b);
                    break;
                case '-':
                    st.push(b-a);
                    break;
                case '*':
                    st.push(b*a);
                    break;
                case '/':
                    st.push(b/a);
                    break;
            }

        }

        return st.top();
        
    }
};
