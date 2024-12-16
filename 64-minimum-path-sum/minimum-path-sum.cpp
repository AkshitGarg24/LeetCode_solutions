class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n,-1);
        for(int i=0;i<m;i++){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    temp[j] = grid[i][j];
                    continue;
                }
                int a = INT_MAX, b = INT_MAX;
                if(i-1>=0){
                    a = grid[i][j] + dp[j];
                }
                if(j-1>=0){
                    b = grid[i][j] + temp[j-1];
                }
                temp[j] = min(a,b);
            }
            dp = temp;
        }
        return dp[n-1];
    }
};