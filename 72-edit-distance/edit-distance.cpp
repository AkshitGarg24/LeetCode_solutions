class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> dp(word2.size()+1);
        for(int i=0;i<=word2.size();i++){
            dp[i] = i;
        }
        vector<int> temp(word2.size()+1);
        for(int i=1;i<=word1.size();i++){
            temp[0] = i;
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1]){
                    temp[j] = dp[j-1];
                    continue;
                }
                temp[j] = 1 + min(dp[j-1],min(dp[j],temp[j-1]));
            }
            dp = temp;
        }
        return dp[word2.size()];
    }
};