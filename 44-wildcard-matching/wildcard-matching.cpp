class Solution {
public:
    bool isMatch(string s, string p) {
        vector<bool> dp(p.size() + 1, false);
        vector<bool> temp(p.size()+1);
        dp[0] = true;
        for (int j = 1; j <= p.size(); ++j) {
            dp[j] = dp[j - 1] && p[j - 1] == '*';
        }
        for (int i = 1; i <= s.size(); ++i) {
            temp[0] = false;
            for (int j = 1; j <= p.size(); ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    temp[j] = dp[j - 1];
                } else if (p[j - 1] == '*') {
                    temp[j] = dp[j] || temp[j - 1] || dp[j - 1];
                } else {
                    temp[j] = false;
                }
            }
            dp = temp;
        }
        return dp[p.size()];
    }
};