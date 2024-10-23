//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    bool dfs(vector<vector<int>> &adj,vector<int> &vis,int i,int parent){
        vis[i] = 1;
        for(auto x : adj[i]){
            if(vis[x]==0){
                bool m = dfs(adj,vis,x,i);
                if(m==true){
                    return true;
                }
            } else if(vis[x]==1 && parent!=x){
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(vector<vector<int>> adj) {
        vector<int> vis(adj.size(),0);
        for(int i=0;i<adj.size();i++){
            if(vis[i]==0){
                bool x = dfs(adj,vis,i,-1);
                if(x==true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends