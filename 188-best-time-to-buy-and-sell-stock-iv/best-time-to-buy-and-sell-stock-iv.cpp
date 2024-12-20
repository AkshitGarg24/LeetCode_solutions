class Solution {
public:
    int maxProfit(int a, vector<int>& nums) {
        vector<vector<int>> dp(2,vector<int> (a+1));
        vector<vector<int>> temp(2,vector<int> (a+1));
        for(int i=0;i<2;i++){
            for(int j=1;j<a+1;j++){
                if(i==0){
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = nums[nums.size()-1];
                }
                
            }
        }
        for(int i=nums.size()-2;i>=0;i--){
            for(int j=1;j>=0;j--){
                temp[j][0] = 0;
                for(int k=1;k<=a;k++){
                    if(j==0){
                        temp[j][k] = max(dp[j][k],-nums[i] + dp[1][k]);
                    } else {
                        temp[j][k] = max(dp[j][k],nums[i]+dp[0][k-1]);
                    }
                }
            }
            dp = temp;
        }
        return dp[0][a];
    }
};