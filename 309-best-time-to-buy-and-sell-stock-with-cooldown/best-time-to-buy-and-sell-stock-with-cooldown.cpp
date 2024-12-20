class Solution {
public:
    int maxProfit(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int> (2));
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=1;j>=0;j--){
                int a = 0, b = 0;
                if(j==0){
                    b  = -nums[i];
                    if(i+1<nums.size()){
                        a = dp[i+1][j], b +=  dp[i+1][1];
                    }
                } else {
                    b = nums[i];
                    if(i+1<nums.size()){
                        a = dp[i+1][j];
                    }
                    if(i+2<nums.size()){
                        b += dp[i+2][0];
                    }
                }
                dp[i][j] = max(a,b);
            }
        }
        return dp[0][0];
    }
};