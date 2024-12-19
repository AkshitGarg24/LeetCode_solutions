class Solution {
public:
    int check(string s,string t,int i, int j,vector<vector<int>> &dp){
        if(j<0){
            return i+1;
        }
        if(i<0){
            return j+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return check(s,t,i-1,j-1,dp);
        }
        return dp[i][j] = min(1+check(s,t,i-1,j-1,dp),min(1+check(s,t,i-1,j,dp),1+check(s,t,i,j-1,dp)));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int> (word2.size(),-1));
        return check(word1,word2,word1.size()-1,word2.size()-1,dp);
    }
};