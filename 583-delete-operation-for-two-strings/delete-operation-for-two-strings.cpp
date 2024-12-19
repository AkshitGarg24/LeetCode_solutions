class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> dp(word2.size());
        vector<int> temp(word2.size());
        for(int i=0;i<word1.size();i++){
            for(int j=0;j<word2.size();j++){
                if(word1[i]==word2[j]){
                    if(i-1>=0 && j-1>=0){
                        temp[j] = dp[j-1];
                    } else {
                        temp[j] = max(i,j);
                    }
                    continue;
                }
                int a = 1e9, b = 1e9, c = 1e9;
                if(i-1>=0 && j-1>=0){
                    a = 2 + dp[j-1];
                } else {
                    a = 2 + max(i+1,j+1);
                }
                if(i-1>=0){
                    b = 1 + dp[j];
                } else {
                    b = 1 + j+1;
                }
                if(j-1>=0){
                    c = 1 + temp[j-1];
                } else {
                    c = 1 + i+1;
                }
                int ans = min(a,min(b,c));
                if(ans>=1e9){
                    temp[j] = 0;
                } else {
                    temp[j] = ans;
                }
            }
            dp = temp;
        }
        return dp[word2.size()-1];
    }
};