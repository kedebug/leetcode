class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.empty()) return 0;

        int maxprofit = 0;
        int minvalue = INFS;
        for (size_t i = 0; i < prices.size(); i++) {
            minvalue = min(prices[i], minvalue);
            int profit = prices[i] - minvalue;
            if (profit > 0) {
                maxprofit += profit;
                minvalue = prices[i];
            }
        }
        return maxprofit;
    }
    //
    // firstly I thought this is a dynamic programming problem
    // but unfortunately, TLE in O(n^2)
    // It's a greed problem in O(n)
    //
    int maxProfit2(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.empty()) return 0;

        vector<int> dp(prices.size());
        dp[0] = 0;
        for (size_t i = 1; i < prices.size(); i++) {
            int maxvalue = prices[i];
            int maxprofit = 0;
            for (int j = i-1; j >= 0; j--) {
                maxvalue = max(maxvalue, prices[j]);
                maxprofit = max(maxprofit, maxvalue - prices[j]);
                dp[i] = max(dp[i], dp[j] + maxprofit);
            }
        }
        return dp[prices.size()-1];
    }
private:
    static const int INFS = 0x3FFFFFFF;
};
