//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    bool detect(vector<vector<int>> &adj,vector<int> &vis,int i){
        queue<pair<int,int>> q;
        q.push({i,-1});
        while(!q.empty()){
            pair<int,int> x = q.front();
            q.pop();
            if(vis[x.first]==0){
                vis[x.first] = 1;
                for(auto a : adj[x.first]){
                    if(!vis[a]){
                        q.push({a,x.first});
                    }
                    else if(x.second!=a){
                        return true;
                    }
                }
            } else {
                return true;
            }
        }
        return false;
    }
  
    bool isCycle(vector<vector<int>> adj) {
        vector<int> vis(adj.size(),0);
        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                bool ans = detect(adj,vis,i);
                if(ans){
                    return ans;
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