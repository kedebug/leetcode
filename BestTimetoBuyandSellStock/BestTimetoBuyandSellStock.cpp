class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int minval = 0x3FFFFFFF;
        int maxprofit = 0;
        for (size_t i = 0; i < prices.size(); i++) {
            minval = min(minval, prices[i]);
            maxprofit = max(maxprofit, prices[i] - minval);
        }
        return maxprofit;
    }
};
