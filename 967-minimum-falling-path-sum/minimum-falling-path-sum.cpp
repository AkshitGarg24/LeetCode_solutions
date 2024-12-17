class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        vector<vector<int>> dp(matrix.size(),vector<int> (matrix.size(),-1));
        for(int i=0;i<matrix.size();i++){
            dp[matrix.size()-1][i] = matrix[matrix.size()-1][i];
        }
        for(int i=matrix.size()-2;i>=0;i--){
            for(int j=matrix.size()-1;j>=0;j--){
                int a = INT_MAX, b = INT_MAX, c = INT_MAX;
                a = dp[i+1][j];
                if(j-1>=0){
                    b = dp[i+1][j-1];
                }
                if(j+1<matrix.size()){
                    c = dp[i+1][j+1];
                }
                dp[i][j] = matrix[i][j] + min(a,min(b,c));  
            }
        }
        for(int i=0;i<matrix.size();i++){
            ans = min(ans,dp[0][i]);
        }
        return ans;
    }
};