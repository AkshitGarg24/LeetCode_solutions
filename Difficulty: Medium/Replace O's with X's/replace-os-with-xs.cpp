//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> w = {1,-1,0,0};
    vector<int> n = {0,0,1,-1};
    void bfs(vector<vector<char>> &mat,vector<vector<int>> &vis,int i,int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            vis[p.first][p.second] = 1;
            for(int o=0;o<4;o++){
                int a = p.first+w[o];
                int b = p.second+n[o];
                if(a>=0 && a<mat.size() && b>=0 && b<mat[0].size() && vis[a][b]==0 && mat[a][b]=='O'){
                    q.push({a,b});
                }
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O' && vis[0][i]==0){
                bfs(mat,vis,0,i);
            }
            if(mat[n-1][i]=='O' && vis[n-1][i]==0){
                bfs(mat,vis,n-1,i);
            }
        }
        for(int i=0;i<mat.size();i++){
            if(mat[i][0]=='O' && vis[i][0]==0){
                bfs(mat,vis,i,0);
            }
            if(mat[i][m-1]=='O' && vis[i][m-1]==0){
                bfs(mat,vis,i,m-1);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' && vis[i][j]==0){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends