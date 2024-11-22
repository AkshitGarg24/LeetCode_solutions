//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void dfs(vector<vector<int>>& adj,vector<int> &ans,int i,vector<int> &vis){
        for(auto x : adj[i]){
            if(!vis[x]){
                vis[x] = 1;
                ans.push_back(x);
                dfs(adj,ans,x,vis);
            }
        }
    }
  
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        vector<int> vis(adj.size(),0);
        vector<int> ans;
        for(int i=0;i<vis.size();i++){
            if(!vis[i]){
                vis[i] = 1;
                ans.push_back(i);
                dfs(adj,ans,i,vis);
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
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends