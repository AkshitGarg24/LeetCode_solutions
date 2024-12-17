class Solution {
public:
    int check(vector<vector<int>> &triangle, int i,int j,vector<vector<int>> &dp){
        if(i==triangle.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j] = triangle[i][j] + min(check(triangle,i+1,j,dp),check(triangle,i+1,j+1,dp));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int> (triangle.size(),-1));
        return check(triangle,0,0,dp);
    }
};