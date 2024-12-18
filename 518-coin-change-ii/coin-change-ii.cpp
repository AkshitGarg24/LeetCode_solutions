class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1));
        for(int i=coins.size()-1;i>=0;i--){
            for(int j=0;j<amount+1;j++){
                if(j==0){
                    dp[i][j] = 1;
                    continue;
                }
                long long int ans = 0;
                for(int x=i;x<coins.size();x++){
                    if(j-coins[x]>=0){
                        ans += dp[x][j-coins[x]];
                    }
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][amount];
    }
};