class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size());
        for(int i=0;i<triangle.size();i++){
            dp[i] = 0;
        }
        for(int i=triangle.size()-1;i>=0;i--){
            vector<int> temp(i+1);
            for(int j=i;j>=0;j--){
                int a = INT_MAX, b = INT_MAX;
                a = dp[j];
                if(j+1<triangle.size()){
                    b = dp[j+1];
                }
                temp[j] = triangle[i][j] + min(a,b);
            }
            dp = temp;
        }
        return dp[0];
    }
};