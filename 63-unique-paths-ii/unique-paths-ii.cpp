class Solution {
public:
    int path(vector<vector<int>>& nums,int m,int n,vector<vector<int>> &dp){
        if(m<0 || n<0 || nums[m][n]==1){
            return 0;
        }
        if(m==0 && n==0){
            return 1;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        return dp[m][n] =  path(nums,m-1,n,dp)+path(nums,m,n-1,dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int> (nums[0].size(),-1));
        return path(nums,nums.size()-1,nums[0].size()-1,dp);
    }
};