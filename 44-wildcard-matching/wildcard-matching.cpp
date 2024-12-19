class Solution {
public:
    bool check(string &s, string &p,int i, int j,vector<vector<int>> &dp){
        if(i==0 || j==0){
            if(i==0 && j==0){
                return true;
            }
            bool ans = true;
            while(i>0){
                if(s[i-1]!='*'){
                    ans = false;
                    break;
                }
                i--;
            }
            while(j>0){
                if(p[j-1]!='*'){
                    ans = false;
                    break;
                }
                j--;
            }
            return ans;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i-1]==p[j-1]){
            return dp[i][j] = check(s,p,i-1,j-1,dp);
        } else if(p[j-1]=='?'){
            return dp[i][j] = check(s,p,i-1,j-1,dp);
        } else if(p[j-1]=='*'){
            bool a = false, b = false, c = false;
            a = check(s,p,i-1,j,dp);
            b = check(s,p,i-1,j-1,dp);
            c = check(s,p,i,j-1,dp);
            return dp[i][j] = a||b||c;
        } else {
            return dp[i][j] = false;
        }
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int> (p.size()+1,-1));
        return check(s,p,s.size(),p.size(),dp);
    }
};