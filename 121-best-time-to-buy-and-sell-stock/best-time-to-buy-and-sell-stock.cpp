class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int x = prices[0];
        int ans = 0;
        for(int i=1;i<prices.size();i++){
            ans = max(ans,prices[i]-x);
            x = min(x,prices[i]);
        }
        return ans;
    }
};