class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        int n = position.size();
        vector<pair<int,double>> CarsTime;
        CarsTime.reserve(n);
        for(int i =0;i<n;++i)
        {
            CarsTime.push_back({position[i], double(target-position[i])/speed[i] });
        }

        sort(CarsTime.begin(),CarsTime.end());
        
        stack<double> st;

        auto * last= CarsTime.data() + n -1 ;

        while(last>=CarsTime.data())
        {
            double Time = last->second;
            if (st.empty())
            {
                st.push(Time);
            }

            else if (Time>st.top()) st.push(Time);
            
            last--;
        }
        return st.size();
        
    }
};
