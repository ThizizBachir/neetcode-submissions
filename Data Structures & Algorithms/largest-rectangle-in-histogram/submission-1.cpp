class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int ,int>> stck;
        int maxx =0;

        for (int i =0; i<heights.size();++i)
        {
            if (stck.empty())
            {
                stck.push({heights[i],i});
                continue;
            }
            int startRec = i;
            while(!stck.empty() && heights[i]<stck.top().first )
            {
                startRec= stck.top().second;
                maxx = max(maxx, (i-startRec)*stck.top().first);
                stck.pop();
            }
            if (stck.empty() && heights[i]!=0 ) stck.push({heights[i],startRec});

            if (!stck.empty() && heights[i]!=0 && heights[i]> stck.top().first) stck.push({heights[i],startRec});

        }
        while (!stck.empty())

        {
            int startRec= stck.top().second;
            maxx = max(maxx, int((heights.size()-startRec)*stck.top().first));
            stck.pop();
        }
        return maxx;
        
    }
};
