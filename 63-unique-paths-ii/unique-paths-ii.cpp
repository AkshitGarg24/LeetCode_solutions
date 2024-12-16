class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int> (nums[0].size(),-1));
        int m = nums.size(), n = nums[0].size();
        if(m<0 || n<0 || nums[m-1][n-1]==1 || nums[0][0]==1){
            return 0;
        }
        dp[0][0] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    continue;
                }
                if(nums[i][j]==1){
                    dp[i][j] = 0;
                    continue;
                }
                int a = 0, b = 0;
                if(i-1>=0){
                    a = dp[i-1][j];
                }
                if(j-1>=0){
                    b = dp[i][j-1];
                }
                dp[i][j] = a+b;
            }
        }
        return dp[m-1][n-1];
    }
};