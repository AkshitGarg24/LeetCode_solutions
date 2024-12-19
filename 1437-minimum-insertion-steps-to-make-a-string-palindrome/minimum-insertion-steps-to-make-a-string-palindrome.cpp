class Solution {
public:
    int minInsertions(string s) {
        vector<int> dp(s.size());
        vector<int> temp(s.size());
        for(int i=s.size()-1;i>=0;i--){
            for(int j=0;j<s.size();j++){
                if(i>j){
                    temp[j] = 0;
                    continue;
                }
                temp[j] = 0;
                if(s[i]==s[j]){
                    if(i+1<s.size() && j-1>=0){
                        temp[j] = dp[j-1];
                    }
                    
                } else {
                    int a = INT_MAX, b = INT_MAX;
                    if(i+1<s.size()){
                        a = 1 + dp[j];
                    }
                    if(j-1>=0){
                        b = 1+temp[j-1];
                    }
                    int ans = min(a,b);
                    if(ans>=INT_MAX){
                        temp[j] = 0;
                    } else {
                        temp[j] = ans;
                    }
                    
                }
            }
            dp = temp;
        }
        return dp[s.size()-1];
    }
};