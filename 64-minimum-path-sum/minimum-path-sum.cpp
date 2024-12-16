class Solution {
public:
    int check(vector<vector<int>> &grid, int m, int n,vector<vector<int>> &dp){
        if(m==0 && n==0){
            return grid[m][n];
        }
        if(m<0 || n<0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int a = INT_MAX, b = INT_MAX;
        if(m-1>=0){
            a = grid[m][n] + check(grid,m-1,n,dp);
        }
        if(n-1>=0){
            b = grid[m][n] + check(grid,m,n-1,dp);
        }
        return dp[m][n] = min(a,b);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return check(grid,m-1,n-1,dp);
    }
};