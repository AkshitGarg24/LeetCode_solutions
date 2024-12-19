class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dp(text2.size());
        vector<int> temp(text2.size());
        for(int i=0;i<text1.size();i++){
            for(int j=0;j<text2.size();j++){
                if(text1[i]==text2[j]){
                    temp[j] = 1;
                    if(i-1>=0 && j-1>=0){
                        temp[j] += dp[j-1];
                    }
                    continue;
                }
                int a = 0, b = 0;
                if(i-1>=0){
                    a = dp[j];
                }
                if(j-1>=0){
                    b = temp[j-1];
                }
                temp[j] = max(a,b);
            }
            dp = temp;
        }
        return dp[text2.size()-1];
    }
};