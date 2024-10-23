//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    vector<int> w = {1,-1,0,0};
    vector<int> l = {0,0,1,-1};
    
    void bfs(vector<vector<int>>& grid,vector<vector<int>> &vis,int i,int j,set<vector<pair<int,int>>> &s){
        queue<pair<int,int>> q;
        q.push({i,j});
        vector<pair<int,int>> v;
        v.push_back({0,0});
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            for(int o=0;o<4;o++){
                int a = p.first+w[o];
                int b = p.second+l[o];
                if(a>=0 && a<grid.size() && b>=0 && b<grid[0].size() && grid[a][b]==1 && vis[a][b]==0){
                    vis[a][b] = 1;
                    q.push({a,b});
                    v.push_back({a-i,b-j});
                }
            }
        }
        s.insert(v);
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size(),0));
        set<vector<pair<int,int>>> s;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    vis[i][j] = 1;
                    bfs(grid,vis,i,j,s);
                }
            }
        }
        return s.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends