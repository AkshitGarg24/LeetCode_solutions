class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<double>> dp(s.size(),vector<double> (t.size(),-1));
        for(int i=0;i<s.size();i++){
            for(int j=0;j<t.size();j++){
                double a = 0, b = 0;
                if(s[i]==t[j]){
                    if(j-1>=0 && i-1>=0){
                        a = dp[i-1][j-1];
                    } else if(j-1<0){
                        a = 1;
                    } else {
                        a = 0;
                    }
                }
                if(i-1>=0){
                    b = dp[i-1][j];
                }
                dp[i][j] = a+b;
            }
        }
        return dp[s.size()-1][t.size()-1];
    }
};