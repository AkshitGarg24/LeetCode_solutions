//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int check(int n,int m, vector<vector<int>> &grid,int i,int j1,int j2,vector<vector<vector<int>>> &dp){
        if(j1<0 || j2< 0 || j1>=m || j2>=m){
            return 0;
        }
        if(i==grid.size()-1){
            if(j1==j2){
                return grid[i][j1];
            }
            return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        int ans = INT_MIN;
        for(int a=-1;a<=1;a++){
            for(int b=-1;b<=1;b++){
                int value;
                if(j1==j2){
                    value = grid[i][j1];
                } else {
                    value = grid[i][j1] + grid[i][j2];
                }
                value += check(n,m,grid,i+1,j1+a,j2+b,dp);
                ans = max(ans,value);
            }
        }
        return dp[i][j1][j2] = ans;
    }
  
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m,-1)));
        return check(n,m,grid,0,0,m-1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends