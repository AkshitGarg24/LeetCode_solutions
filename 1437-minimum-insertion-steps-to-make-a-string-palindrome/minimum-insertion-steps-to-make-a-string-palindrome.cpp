class Solution {
public:
    int minInsertions(string s) {
        vector<vector<int>> dp(s.size(),vector<int> (s.size()));
        for(int i=s.size()-1;i>=0;i--){
            for(int j=0;j<s.size();j++){
                if(i>j){
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = 0;
                if(s[i]==s[j]){
                    if(i+1<s.size() && j-1>=0){
                        dp[i][j] = dp[i+1][j-1];
                    }
                    
                } else {
                    int a = INT_MAX, b = INT_MAX;
                    if(i+1<s.size()){
                        a = 1 + dp[i+1][j];
                    }
                    if(j-1>=0){
                        b = 1+dp[i][j-1];
                    }
                    int ans = min(a,b);
                    if(ans>=INT_MAX){
                        dp[i][j] = 0;
                    } else {
                        dp[i][j] = ans;
                    }
                    
                }
            }
        }
        return dp[0][s.size()-1];
    }
};