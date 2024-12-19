//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        int res = 0;
        vector<vector<int>> dp(s1.size(),vector<int> (s2.size(),-1));
        for(int i=0;i<s1.size();i++){
            for(int j=0;j<s2.size();j++){
                if(s1[i]!=s2[j]){
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = 1;
                    if(i-1>=0 && j-1>=0){
                        dp[i][j] += dp[i-1][j-1];
                    }
                }
                res = max(res,dp[i][j]);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends