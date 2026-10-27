class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int lIndex = 0;
        int hIndex = 0;
        int result =0;
        for(int i =1 ; i<n;++i)
        {
            if (prices[i]<prices[lIndex])
            { lIndex =i; hIndex = i;}
            else {hIndex = i;} 
            result = max(result,prices[hIndex]-prices[lIndex]);

        }
        return result;
        
    }
};
