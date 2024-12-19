class Solution {
public:
    int numDistinct(string s, string t) {
        vector<double> dp(t.size());
        vector<double> temp(t.size());
        for(int i=0;i<s.size();i++){
            for(int j=0;j<t.size();j++){
                double a = 0, b = 0;
                if(s[i]==t[j]){
                    if(j-1>=0 && i-1>=0){
                        a = dp[j-1];
                    } else if(j-1<0){
                        a = 1;
                    } else {
                        a = 0;
                    }
                }
                if(i-1>=0){
                    b = dp[j];
                }
                temp[j] = a+b;
            }
            dp = temp;
        }
        return dp[t.size()-1];
    }
};