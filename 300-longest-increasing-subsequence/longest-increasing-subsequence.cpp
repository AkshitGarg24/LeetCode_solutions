class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int> (nums.size()+1,0));
        for(int i=1;i<nums.size()+1;i++){
            for(int j=0;j<nums.size()+1;j++){
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
                int maxi;
                if(j==nums.size()){
                    maxi = INT_MAX;
                } else {
                    maxi = nums[j];
                }
                if(nums[i-1]<maxi){
                    dp[i][j] = max(dp[i][j],1 + dp[i-1][i-1]);
                }
            }
        }
        return dp[nums.size()][nums.size()];
    }
};