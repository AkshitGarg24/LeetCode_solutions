//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<vector<int>> adj) {
        int size = 0;
        vector<int> vis(v,0);
        for(int i=0;i<adj.size();i++){
            for(auto x : adj[i]){
                vis[x]++;
            }
        }
        queue<int> q;
        for(int i=0;i<vis.size();i++){
            if(vis[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();
            size++;
            for(auto i : adj[x]){
                vis[i]--;
                if(vis[i]==0){
                    q.push(i);
                }
            }
        }
        return !(size==v);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends