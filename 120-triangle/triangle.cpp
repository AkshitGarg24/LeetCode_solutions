class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size()+1,vector<int> (triangle.size(),-1));
        for(int i=0;i<triangle.size();i++){
            dp[triangle.size()][i] = 0;
        }
        for(int i=triangle.size()-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                int a = INT_MAX, b = INT_MAX;
                a = dp[i+1][j];
                if(j+1<triangle.size()){
                    b = dp[i+1][j+1];
                }
                dp[i][j] = triangle[i][j] + min(a,b);
            }
        }
        return dp[0][0];
    }
};