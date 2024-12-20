class Solution {
public:
    int maxProfit(vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>> (2,vector<int> (3,-1)));
        for(int i=0;i<2;i++){
            for(int j=1;j<3;j++){
                if(i==0){
                    dp[nums.size()-1][i][j] = 0;
                } else {
                    dp[nums.size()-1][i][j] = nums[nums.size()-1];
                }
                
            }
        }
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<2;j++){
                dp[i][j][0] = 0;
            }
        }
        for(int i=nums.size()-2;i>=0;i--){
            for(int j=1;j>=0;j--){
                for(int k=1;k<=2;k++){
                    if(j==0){
                        dp[i][j][k] = max(dp[i+1][j][k],-nums[i] + dp[i+1][1][k]);
                    } else {
                        dp[i][j][k] = max(dp[i+1][j][k],nums[i]+dp[i+1][0][k-1]);
                    }
                }
            }
        }
        return dp[0][0][2];
    }
};