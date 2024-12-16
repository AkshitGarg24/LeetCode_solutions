class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        vector<int> dp(nums[0].size(),0);
        int m = nums.size(), n = nums[0].size();
        if(nums[m-1][n-1]==1 || nums[0][0]==1){
            return 0;
        }
        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    temp[j] = 1;
                    continue;
                }
                if(nums[i][j]==1){
                    temp[j] = 0;
                    continue;
                }
                int a = 0, b = 0;
                if(i-1>=0){
                    a = dp[j];
                }
                if(j-1>=0){
                    b = temp[j-1];
                }
                temp[j] = a+b;
            }
            dp = temp;
        }
        return dp[n-1];
    }
};