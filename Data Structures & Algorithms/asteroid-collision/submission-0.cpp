class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> pos;
        int neg=0;
        int n = asteroids.size();

        vector<int> v;


        // i is the first positive;

        for(int i =0; i<n;++i)
        {
            int size = asteroids[i];
            if(size>0) 
            {
                pos.push(size); continue;
            }
            else
            {
                if(pos.empty())
                {
                    v.push_back(size);
                    continue;
                }

                bool isDestroyed = false;
                while(!pos.empty())
                {

                    int t = pos.top();
                    if(t==-size)
                    {
                        isDestroyed = true;
                        pos.pop(); 
                        break;
                    }
                    if(t>-size)
                    {
                        isDestroyed = true;
                        break;
                    }
                    if(t<-size)
                    {
                        pos.pop();
                    }
                    
                }
                if(pos.empty()&& !isDestroyed) v.push_back(size);
            }
        }

        vector<int> posv;
        while(!pos.empty()) 
        {
            posv.push_back(pos.top());
            pos.pop();
        }

        for(int i = posv.size()-1;i>=0;--i)
        {
            v.push_back(posv[i]);
        }
        return v;


        
        
    }
};