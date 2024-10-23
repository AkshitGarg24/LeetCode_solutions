//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> w = {1,-1,0,0};
    vector<int> z = {0,0,1,-1};
    
    int numberOfEnclaves(vector<vector<int>> &mat) {
        int m = mat[0].size();
        int n = mat.size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && mat[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            vis[p.first][p.second] = 1;
            for(int o=0;o<4;o++){
                int a = p.first+w[o];
                int b = p.second+z[o];
                if(a>=0 && a<mat.size() && b>=0 && b<mat[0].size() && vis[a][b]==0 && mat[a][b]==1){
                    q.push({a,b});
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && vis[i][j]==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends