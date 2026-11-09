class Solution {
public:
    int calPoints(vector<string>& operations) {

        stack<int> s;
        for(auto str : operations)
        {
            if(str == "D")
            {
                s.push(s.top()*2);
                continue;
            }

            if(str == "+")
            {

                int a = s.top();
                s.pop();
                int b = s.top();
                s.push(a);
                s.push(a+b);
                continue;
            }
            if(str == "C")
            {
                s.pop();
                continue;
            }
            s.push(stoi(str));
        }
        int sum =0;
        while(!s.empty())
        {
            sum+= s.top();
            s.pop();
        }
        return sum;
        
    }
};