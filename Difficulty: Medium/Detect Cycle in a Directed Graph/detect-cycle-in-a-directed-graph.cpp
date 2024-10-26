//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    bool check(vector<vector<int>> &adj,int v,vector<int> &vis,vector<int> &pathvis,int i){
        vis[i] = 1;
        pathvis[i] = 1;
        for(auto x : adj[i]){
            if(pathvis[x]==1){
                return true;
            }
            if(vis[x]==0){
                bool m = check(adj,v,vis,pathvis,x);
                if(m){
                    return true;
                }
            }
        }
        pathvis[i] = 0;
        return false;
    }
    
    bool isCyclic(int v, vector<vector<int>> adj) {
        vector<int> vis(v,0);
        vector<int> pathvis(v,0);
        for(int i=0;i<v;i++){
            if(vis[i]==0){
                bool m = check(adj,v,vis,pathvis,i);
                if(m){
                    return true;
                }
            }
        }
        return false;
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