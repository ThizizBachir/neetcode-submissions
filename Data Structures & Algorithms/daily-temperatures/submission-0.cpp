class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        stack<int> st;
        vector<int > result(temperatures.size() ,0) ;
        int *  r = temperatures.data() + temperatures.size() -1;

        while (r>= temperatures.data())
        {
            int currentIndex = r-temperatures.data();
            while  (!st.empty() && temperatures[st.top()]<= temperatures[currentIndex])
            {
                st.pop();
            }


            if(!st.empty()) result[currentIndex] = st.top()-currentIndex;
            else result[currentIndex] = 0;

            st.push(currentIndex);
            r--;
        }

        return result;
        
    }
};
