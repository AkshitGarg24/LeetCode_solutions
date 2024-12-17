class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        vector<int> dp(matrix.size(),-1);
        vector<int> temp(matrix.size());
        for(int i=0;i<matrix.size();i++){
            dp[i] = matrix[matrix.size()-1][i];
        }
        for(int i=matrix.size()-2;i>=0;i--){
            
            for(int j=matrix.size()-1;j>=0;j--){
                int a = INT_MAX, b = INT_MAX, c = INT_MAX;
                a = dp[j];
                if(j-1>=0){
                    b = dp[j-1];
                }
                if(j+1<matrix.size()){
                    c = dp[j+1];
                }
                temp[j] = matrix[i][j] + min(a,min(b,c));  
            }
            dp = temp;
        }
        for(int i=0;i<matrix.size();i++){
            ans = min(ans,dp[i]);
        }
        return ans;
    }
};