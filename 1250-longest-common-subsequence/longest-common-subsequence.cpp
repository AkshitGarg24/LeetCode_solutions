class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int> (text2.size(),-1));
        for(int i=0;i<text1.size();i++){
            for(int j=0;j<text2.size();j++){
                if(text1[i]==text2[j]){
                    dp[i][j] = 1;
                    if(i-1>=0 && j-1>=0){
                        dp[i][j] += dp[i-1][j-1];
                    }
                    continue;
                }
                int a = 0, b = 0;
                if(i-1>=0){
                    a = dp[i-1][j];
                }
                if(j-1>=0){
                    b = dp[i][j-1];
                }
                dp[i][j] = max(a,b);
            }
        }
        return dp[text1.size()-1][text2.size()-1];
    }
};