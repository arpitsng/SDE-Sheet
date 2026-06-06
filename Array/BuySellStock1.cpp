//optimal greedy
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxPro = 0, minBuy = prices[0];

        for(int i=0; i<n; i++){
            minBuy = min(minBuy, prices[i]);
            maxPro = max(maxPro, prices[i] - minBuy);
        } 

        return maxPro;
    }
};


