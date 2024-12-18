class Solution {
public:
    int check(vector<int> &coins,int amount,vector<int> &dp){
        if(amount<0){
            return 1e9;
        }
        if(amount==0){
            return 0;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int ans = INT_MAX;
        for(int i=0;i<coins.size();i++){
            ans = min(ans,1 + check(coins,amount-coins[i],dp));
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int a = check(coins,amount,dp);
        if(a>=1e9){
            return -1;
        }
        return a;
    }
};