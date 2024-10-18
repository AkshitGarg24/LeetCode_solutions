//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void dfs(int node,vector<int> &vis,vector<int> &ans,vector<vector<int>>& adj){
        if(vis[node]==1){
            return;
        }
        vis[node] = 1;
        ans.push_back(node);
        for(auto it : adj[node]){
            if(vis[it]!=1){
                dfs(it,vis,ans,adj);
            }
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        vector<int> vis(adj.size(),-1);
        vector<int> ans;
        
        dfs(0,vis,ans,adj);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends