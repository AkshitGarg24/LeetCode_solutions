class Solution {
public:
    int maxProfit(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int> (2,0));
        dp[nums.size()-1][0] = 0;
        dp[nums.size()-1][1] = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            for(int j=1;j>=0;j--){
                dp[i][j] = max(dp[i][j],dp[i+1][j]);
                if(j==0){
                    dp[i][j] = max(dp[i][j],dp[i+1][1]-nums[i]);
                } else {
                    dp[i][j] = max(dp[i][j],nums[i] + dp[i+1][0]);
                }
            }
        }
        return dp[0][0];
    }
};