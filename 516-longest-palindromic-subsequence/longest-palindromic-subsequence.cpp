class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(),vector<int> (s.size(),-1));
        for(int i=s.size()-1;i>=0;i--){
            for(int j=0;j<s.size();j++){
                if(i>j){
                    dp[i][j] = 0;
                    continue;
                }
                if(s[i]==s[j]){
                    if(i==j){
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 2;
                    }
                    if(i+1<s.size() && j-1>=0){
                        dp[i][j] += dp[i+1][j-1];
                    }
                } else {
                    int a = 0, b = 0;
                    if(i+1<s.size()){
                        a = dp[i+1][j];
                    }
                    if(j-1>=0){
                        b = dp[i][j-1];
                    }
                    dp[i][j] = max(a,b);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};