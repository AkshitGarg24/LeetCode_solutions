//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    int check(vector<vector<int>> &cost,vector<vector<int>> &dp,int i,int mask){
        if(mask==(1<<cost.size())-1){
            return cost[i][0];
        }
        if(dp[mask][i] != -1){
            return dp[mask][i];
        }
        
        int ans = INT_MAX;
        for(int j=0;j<cost.size();j++){
            if((mask & (1<<j))==0){
                int a = cost[i][j] + check(cost,dp,j,(mask|(1<<j)));
                ans = min(ans,a);
            }
        }
        return dp[mask][i] = ans;
    }
    
    int total_cost(vector<vector<int>>cost){
        vector<vector<int>> dp(1<<cost.size(),vector<int> (cost.size(),-1));
        return check(cost,dp,0,1);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends