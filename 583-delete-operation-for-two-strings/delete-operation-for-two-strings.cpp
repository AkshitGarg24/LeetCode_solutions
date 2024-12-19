class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int> (word2.size(),0));
        for(int i=0;i<word1.size();i++){
            for(int j=0;j<word2.size();j++){
                if(word1[i]==word2[j]){
                    if(i-1>=0 && j-1>=0){
                        dp[i][j] = dp[i-1][j-1];
                    } else {
                        dp[i][j] = max(i,j);
                    }
                    continue;
                }
                int a = 1e9, b = 1e9, c = 1e9;
                if(i-1>=0 && j-1>=0){
                    a = 2 + dp[i-1][j-1];
                } else {
                    a = 2 + max(i+1,j+1);
                }
                if(i-1>=0){
                    b = 1 + dp[i-1][j];
                } else {
                    b = 1 + j+1;
                }
                if(j-1>=0){
                    c = 1 + dp[i][j-1];
                } else {
                    c = 1 + i+1;
                }
                int ans = min(a,min(b,c));
                if(ans>=1e9){
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = ans;
                }
            }
        }
        return dp[word1.size()-1][word2.size()-1];
    }
};