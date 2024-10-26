//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool check(int v,vector<int> adj[],vector<int> &vis,int i){
        vis[i] = 1;
        for(auto x : adj[i]){
            if(vis[x]==1){
                return true;
            }
            bool m = check(v,adj,vis,x);
            if(m){
                return true;
            }
        }
        vis[i] = 0;
        return false;
    }
    
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        vector<int> ans;
        vector<int> vis(v,0);
        for(int i=0;i<v;i++){
            bool m = check(v,adj,vis,i);
            if(!m){
                ans.push_back(i);
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

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends