class Solution {
public:
    int check(int amount,vector<int> &coins,int idx,vector<vector<int>> &dp){
        if(amount<0){
            return 0;
        }
        if(amount==0){
            return 1;
        }
        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }
        int ans = 0;
        for(int i=idx;i<coins.size();i++){
            ans += check(amount-coins[i],coins,i,dp);
        }
        return dp[idx][amount] = ans;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        return check(amount,coins,0,dp);
    }
};