class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> dp(prices.size());   
        vector<int> rdp(prices.size());
        int minval = 0x3fffffff;
        int maxprofit = 0;
        size_t i = 0;
        for (auto iter = prices.begin(); iter != prices.end(); iter++) {
            minval = min(minval, *iter);
            maxprofit = max(maxprofit, *iter - minval);
            dp[i++] = maxprofit;
        }
        int maxval = 0;
        maxprofit = 0;
        i = prices.size() - 1;
        for (auto iter = prices.rbegin(); iter != prices.rend(); iter++) {
            maxval = max(maxval, *iter);
            maxprofit = max(maxprofit, maxval - *iter);
            rdp[i--] = maxprofit;
        }
        int result = 0;
        for (i = 0; i < dp.size(); i++) {
            result = max(result, dp[i] + rdp[i]);
        }
        return result;
    }
};
