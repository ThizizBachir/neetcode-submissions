class StockSpanner {
public:
    stack<pair<int,int>> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(s.empty() || s.top().first>price) 
        {
            s.push({price,1});
            return 1;
        }

        int k=1;
        while(!s.empty() && s.top().first<=price)
        {
            k+=s.top().second;
            s.pop();
        }

        s.push({price,k});
        return k;

        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */