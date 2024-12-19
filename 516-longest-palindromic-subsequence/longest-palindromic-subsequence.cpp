class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<int> dp(s.size());
        vector<int> temp(s.size());
        for(int i=s.size()-1;i>=0;i--){
            for(int j=0;j<s.size();j++){
                if(i>j){
                    temp[j] = 0;
                    continue;
                }
                if(s[i]==s[j]){
                    if(i==j){
                        temp[j] = 1;
                    } else {
                        temp[j] = 2;
                    }
                    if(i+1<s.size() && j-1>=0){
                        temp[j] += dp[j-1];
                    }
                } else {
                    int a = 0, b = 0;
                    if(i+1<s.size()){
                        a = dp[j];
                    }
                    if(j-1>=0){
                        b = temp[j-1];
                    }
                    temp[j] = max(a,b);
                }
            }
            dp = temp;
        }
        return dp[s.size()-1];
    }
};