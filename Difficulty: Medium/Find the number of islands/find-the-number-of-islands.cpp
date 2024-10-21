//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void traverse(vector<vector<char>>& grid,vector<vector<int>> &vis,int i,int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            pair<int,int> x = q.front();
            q.pop();
            if(x.first<0 || x.first>=vis.size() || x.second<0 || x.second>=vis[0].size()){
                continue;
            }
            if(grid[x.first][x.second]=='1' && vis[x.first][x.second]==-1){
                vis[x.first][x.second] = 1;
                q.push({x.first+1,x.second});
                q.push({x.first-1,x.second});
                q.push({x.first,x.second+1});
                q.push({x.first,x.second-1});
                q.push({x.first+1,x.second+1});
                q.push({x.first+1,x.second-1});
                q.push({x.first-1,x.second+1});
                q.push({x.first-1,x.second-1});
            }
        }
    }
  
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,-1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==-1){
                    ans++;
                    traverse(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends