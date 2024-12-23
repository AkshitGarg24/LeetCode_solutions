class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        vector<vector<int>> dp(cuts.size(),vector<int> (cuts.size(),0));
        sort(cuts.begin(),cuts.end());
        for(int i=cuts.size()-2;i>=1;i--){
            for(int j=1;j<=cuts.size()-2;j++){
                if(i>j){
                    continue;
                }
                int ans = INT_MAX;
                for(int x = i;x<=j;x++){
                    int steps = cuts[j+1] - cuts[i-1] + dp[i][x-1] + dp[x+1][j];
                    ans = min(ans,steps); 
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][cuts.size()-2];
    }
};